#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

class DrivePublisher : public rclcpp::Node
{
public:
    DrivePublisher()
    : Node("drive_publisher"),
      tf_buffer_(std::make_shared<tf2_ros::Buffer>(this->get_clock())),
      tf_listener_(std::make_shared<tf2_ros::TransformListener>(*tf_buffer_))
    {
        // Declare and get the parameter 'distance'
        this->declare_parameter<int>("distance", 0);
        distance_ = this->get_parameter("distance").as_int();

        // Create a publisher for PoseStamped messages
        publisher_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/goal_pose", 10);

        // Create a timer to repeatedly publish the goal pose
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&DrivePublisher::publish_goal_pose, this));

        RCLCPP_INFO(this->get_logger(), "Drive Publisher Node has been started.");
    }

private:
    void publish_goal_pose()
    {
        geometry_msgs::msg::PoseStamped current_pose;

        // Try to get the transform from the 'base_link' frame to the 'map' frame
        try {
            // Lookup the transform between the robot base and the global frame
            geometry_msgs::msg::TransformStamped transform_stamped;
            transform_stamped = tf_buffer_->lookupTransform(
                "map", "base_link", tf2::TimePointZero);

            // Convert TransformStamped to PoseStamped
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

            goal_pose.pose.position.x += static_cast<double>(distance_);

            publisher_->publish(goal_pose);

            RCLCPP_INFO(this->get_logger(), "Published goal pose: (x: %f, y: %f)",
                        goal_pose.pose.position.x, goal_pose.pose.position.y);
            abort();
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
    int distance_;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DrivePublisher>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}

