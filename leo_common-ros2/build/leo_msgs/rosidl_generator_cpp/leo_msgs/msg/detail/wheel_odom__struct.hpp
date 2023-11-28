// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from leo_msgs:msg/WheelOdom.idl
// generated code does not contain a copyright notice

#ifndef LEO_MSGS__MSG__DETAIL__WHEEL_ODOM__STRUCT_HPP_
#define LEO_MSGS__MSG__DETAIL__WHEEL_ODOM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__leo_msgs__msg__WheelOdom __attribute__((deprecated))
#else
# define DEPRECATED__leo_msgs__msg__WheelOdom __declspec(deprecated)
#endif

namespace leo_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WheelOdom_
{
  using Type = WheelOdom_<ContainerAllocator>;

  explicit WheelOdom_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->velocity_lin = 0.0f;
      this->velocity_ang = 0.0f;
      this->pose_x = 0.0f;
      this->pose_y = 0.0f;
      this->pose_yaw = 0.0f;
    }
  }

  explicit WheelOdom_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->velocity_lin = 0.0f;
      this->velocity_ang = 0.0f;
      this->pose_x = 0.0f;
      this->pose_y = 0.0f;
      this->pose_yaw = 0.0f;
    }
  }

  // field types and members
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _velocity_lin_type =
    float;
  _velocity_lin_type velocity_lin;
  using _velocity_ang_type =
    float;
  _velocity_ang_type velocity_ang;
  using _pose_x_type =
    float;
  _pose_x_type pose_x;
  using _pose_y_type =
    float;
  _pose_y_type pose_y;
  using _pose_yaw_type =
    float;
  _pose_yaw_type pose_yaw;

  // setters for named parameter idiom
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__velocity_lin(
    const float & _arg)
  {
    this->velocity_lin = _arg;
    return *this;
  }
  Type & set__velocity_ang(
    const float & _arg)
  {
    this->velocity_ang = _arg;
    return *this;
  }
  Type & set__pose_x(
    const float & _arg)
  {
    this->pose_x = _arg;
    return *this;
  }
  Type & set__pose_y(
    const float & _arg)
  {
    this->pose_y = _arg;
    return *this;
  }
  Type & set__pose_yaw(
    const float & _arg)
  {
    this->pose_yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    leo_msgs::msg::WheelOdom_<ContainerAllocator> *;
  using ConstRawPtr =
    const leo_msgs::msg::WheelOdom_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<leo_msgs::msg::WheelOdom_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<leo_msgs::msg::WheelOdom_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      leo_msgs::msg::WheelOdom_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<leo_msgs::msg::WheelOdom_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      leo_msgs::msg::WheelOdom_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<leo_msgs::msg::WheelOdom_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<leo_msgs::msg::WheelOdom_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<leo_msgs::msg::WheelOdom_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__leo_msgs__msg__WheelOdom
    std::shared_ptr<leo_msgs::msg::WheelOdom_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__leo_msgs__msg__WheelOdom
    std::shared_ptr<leo_msgs::msg::WheelOdom_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WheelOdom_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->velocity_lin != other.velocity_lin) {
      return false;
    }
    if (this->velocity_ang != other.velocity_ang) {
      return false;
    }
    if (this->pose_x != other.pose_x) {
      return false;
    }
    if (this->pose_y != other.pose_y) {
      return false;
    }
    if (this->pose_yaw != other.pose_yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const WheelOdom_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WheelOdom_

// alias to use template instance with default allocator
using WheelOdom =
  leo_msgs::msg::WheelOdom_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace leo_msgs

#endif  // LEO_MSGS__MSG__DETAIL__WHEEL_ODOM__STRUCT_HPP_
