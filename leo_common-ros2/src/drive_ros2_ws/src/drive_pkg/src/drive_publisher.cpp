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
        //get params
        this->declare_parameter<int>("x", 0);
        this->declare_parameter<int>("y", 0);
        x_ = this->get_parameter("x").as_int();
        y_ = this->get_parameter("y").as_int();

        
        publisher_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/goal_pose", 10);

        
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&DrivePublisher::publish_goal_pose, this));

        RCLCPP_INFO(this->get_logger(), "Drive Publisher Node has been started.");
    }

private:
    void publish_goal_pose()
    {
        geometry_msgs::msg::PoseStamped current_pose;

        
        try {
            
            geometry_msgs::msg::TransformStamped transform_stamped;
            transform_stamped = tf_buffer_->lookupTransform(
                "map", "base_link", tf2::TimePointZero);

            //get current
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
            
            //calc yaw and quat
            double yaw_degrees = static_cast<double>(y_);
            double yaw_radians = yaw_degrees * M_PI / 180.0;

            tf2::Quaternion q_orig, q_rot, q_new;
            tf2::fromMsg(current_pose.pose.orientation, q_orig);
            double roll, pitch, yaw;
            tf2::Matrix3x3(q_orig).getRPY(roll, pitch, yaw);

        

    
            tf2::fromMsg(goal_pose.pose.orientation, q_orig);
            q_rot.setRPY(0, 0, yaw_radians);  // Yaw rotation only
            q_new = q_rot * q_orig;
            q_new.normalize();
            
            if (yaw_degrees != 0) {
                yaw += yaw_radians;
            }

            //distribute components for translational and rot
            double dx = static_cast<double>(x_) * cos(yaw);
            double dy = static_cast<double>(x_) * sin(yaw);

            goal_pose.pose.position.x += static_cast<double>(dx);
            goal_pose.pose.position.y += static_cast<double>(dy);
            
            goal_pose.pose.orientation = tf2::toMsg(q_new);

            publisher_->publish(goal_pose);

            RCLCPP_INFO(this->get_logger(), "Published goal pose: (x: %f, y: %f, z: %f)",
                        goal_pose.pose.position.x, goal_pose.pose.position.y, goal_pose.pose.orientation.z);
            
            rclcpp::shutdown();
//abort();
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
    int x_;
    int y_;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DrivePublisher>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}
