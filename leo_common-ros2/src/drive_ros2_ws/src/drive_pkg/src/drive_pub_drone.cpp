#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdexcept>

class DrivePublisher : public rclcpp::Node
{
public:
    DrivePublisher()
    : Node("drive_publisher"),
      tf_buffer_(std::make_shared<tf2_ros::Buffer>(this->get_clock())),
      tf_listener_(std::make_shared<tf2_ros::TransformListener>(*tf_buffer_))
    {
        this->declare_parameter<double>("x_offset", 0.0);
        this->declare_parameter<double>("y_offset", 0.0);
        this->declare_parameter<double>("z_offset", 0.0);
        x_offset_ = this->get_parameter("x_offset").as_double();
        y_offset_ = this->get_parameter("y_offset").as_double();
        z_offset_ = this->get_parameter("y_offset").as_double();

        publisher_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/goal_pose", 10);

        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&DrivePublisher::publish_goal_pose, this));

        RCLCPP_INFO(this->get_logger(), "Drive Publisher Node has been started.");
    }

private:
    double calculate_distance_straight_line(double target_height, double launcher_angle = 60.0, double rover_angle = 0.0, double launcher_height = 1.0 / 3.0) {
        double effective_angle = launcher_angle + rover_angle;
        double tan_angle = std::tan(effective_angle * M_PI / 180.0);

        if (effective_angle == 0.0 || effective_angle == 90.0) {
            throw std::runtime_error("Error: Division by zero");
        }

        double distance = (target_height - launcher_height) / tan_angle;
        return distance;
    }

    std::pair<double, double> new_waypoint(double x, double y, double target_height) {
        double r = std::sqrt(x * x + y * y);
        double offset = calculate_distance_straight_line(target_height);

        if (r == 0) {
            throw std::runtime_error("Error: Division by zero when normalizing coordinates.");
        }

        double new_x = x * (r - offset) / r;
        double new_y = y * (r - offset) / r;

        return {new_x, new_y};
    }
    void publish_goal_pose()
    {
        geometry_msgs::msg::PoseStamped current_pose;

        try {
            geometry_msgs::msg::TransformStamped transform_stamped;
            transform_stamped = tf_buffer_->lookupTransform(
                "map", "base_link", tf2::TimePointZero);

            current_pose.header.stamp = this->get_clock()->now();
            current_pose.header.frame_id = "map";
            current_pose.pose.position.x = transform_stamped.transform.translation.x;
            current_pose.pose.position.y = transform_stamped.transform.translation.y;
            current_pose.pose.position.z = transform_stamped.transform.translation.z;
            current_pose.pose.orientation = transform_stamped.transform.rotation;

            RCLCPP_INFO(this->get_logger(), "Current pose: (x: %f, y: %f, z: %f)",
                        current_pose.pose.position.x, current_pose.pose.position.y, current_pose.pose.position.z);

            geometry_msgs::msg::PoseStamped goal_pose;
            goal_pose.header.frame_id = current_pose.header.frame_id;
            goal_pose.header.stamp = this->get_clock()->now();

            goal_pose.pose = current_pose.pose;

            auto [x_final, y_final] = new_waypoint(x_offset_, y_offset_, z_offset_);
            goal_pose.pose.position.x += x_final;
            goal_pose.pose.position.y += y_final;

            publisher_->publish(goal_pose);

            RCLCPP_INFO(this->get_logger(), "Published goal pose: (x: %f, y: %f)",
                        goal_pose.pose.position.x, goal_pose.pose.position.y);
        }
        catch (tf2::TransformException &ex) {
            RCLCPP_WARN(this->get_logger(), "Could not transform: %s", ex.what());
            return;
        }
    }

    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
    double x_offset_;
    double y_offset_;
    double z_offset_;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DrivePublisher>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}
