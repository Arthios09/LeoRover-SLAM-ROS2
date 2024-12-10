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

        // Subscribe to the "zed/zed_node/pose" topic
        subscription_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
            "zed/zed_node/pose",
            10,
            std::bind(&DrivePublisher::pose_callback, this, std::placeholders::_1));

        RCLCPP_INFO(this->get_logger(), "Drive Publisher Node has been started.");
    }

private:
    void pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr zed_pose)
    {
        geometry_msgs::msg::PoseStamped current_pose;

        // Try to get the transform from the 'base_link' frame to the 'map' frame
        try {
            geometry_msgs::msg::TransformStamped transform_stamped;
            transform_stamped = tf_buffer_->lookupTransform(
                "map", "base_link", tf2::TimePointZero);

            // Convert TransformStamped to PoseStamped
            current_pose.header.stamp = this->get_clock()->now();
            current_pose.header.frame_id = "map";
            current_pose.pose.position.x = transform_stamped.transform.translation.x;
            current_pose.pose.position.y = transform_stamped.transform.translation.y;
            current_pose.pose.orientation = transform_stamped.transform.rotation;

            RCLCPP_INFO(this->get_logger(), "Current pose: (x: %f, y: %f, z: %f)",
                        current_pose.pose.position.x, current_pose.pose.position.y, current_pose.pose.position.z);

            // Combine the current pose with the ZED pose
            geometry_msgs::msg::PoseStamped goal_pose;
            goal_pose.header.frame_id = current_pose.header.frame_id;
            goal_pose.header.stamp = this->get_clock()->now();

            goal_pose.pose.position.x = current_pose.pose.position.x + zed_pose->pose.position.x;
            goal_pose.pose.position.y = current_pose.pose.position.y + zed_pose->pose.position.y;
            goal_pose.pose.orientation = current_pose.pose.orientation; // Keep the same orientation

            // Publish the goal pose
            publisher_->publish(goal_pose);

            RCLCPP_INFO(this->get_logger(), "Published goal pose: (x: %f, y: %f, z: %f)",
                        goal_pose.pose.position.x, goal_pose.pose.position.y, goal_pose.pose.position.z);
        }
        catch (tf2::TransformException &ex) {
            RCLCPP_WARN(this->get_logger(), "Could not transform: %s", ex.what());
            return;
        }
    }

    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr subscription_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr publisher_;
    std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
    int distance_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DrivePublisher>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}

