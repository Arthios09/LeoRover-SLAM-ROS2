// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from leo_msgs:msg/WheelStates.idl
// generated code does not contain a copyright notice
#include "leo_msgs/msg/detail/wheel_states__rosidl_typesupport_fastrtps_cpp.hpp"
#include "leo_msgs/msg/detail/wheel_states__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace builtin_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const builtin_interfaces::msg::Time &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  builtin_interfaces::msg::Time &);
size_t get_serialized_size(
  const builtin_interfaces::msg::Time &,
  size_t current_alignment);
size_t
max_serialized_size_Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace builtin_interfaces


namespace leo_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_leo_msgs
cdr_serialize(
  const leo_msgs::msg::WheelStates & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: stamp
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.stamp,
    cdr);
  // Member: position
  {
    cdr << ros_message.position;
  }
  // Member: velocity
  {
    cdr << ros_message.velocity;
  }
  // Member: torque
  {
    cdr << ros_message.torque;
  }
  // Member: pwm_duty_cycle
  {
    cdr << ros_message.pwm_duty_cycle;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_leo_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  leo_msgs::msg::WheelStates & ros_message)
{
  // Member: stamp
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.stamp);

  // Member: position
  {
    cdr >> ros_message.position;
  }

  // Member: velocity
  {
    cdr >> ros_message.velocity;
  }

  // Member: torque
  {
    cdr >> ros_message.torque;
  }

  // Member: pwm_duty_cycle
  {
    cdr >> ros_message.pwm_duty_cycle;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_leo_msgs
get_serialized_size(
  const leo_msgs::msg::WheelStates & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: stamp

  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.stamp, current_alignment);
  // Member: position
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.position[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: velocity
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.velocity[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: torque
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.torque[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pwm_duty_cycle
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.pwm_duty_cycle[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_leo_msgs
max_serialized_size_WheelStates(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: stamp
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        builtin_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: position
  {
    size_t array_size = 4;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: velocity
  {
    size_t array_size = 4;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: torque
  {
    size_t array_size = 4;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pwm_duty_cycle
  {
    size_t array_size = 4;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _WheelStates__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const leo_msgs::msg::WheelStates *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _WheelStates__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<leo_msgs::msg::WheelStates *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _WheelStates__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const leo_msgs::msg::WheelStates *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _WheelStates__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_WheelStates(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _WheelStates__callbacks = {
  "leo_msgs::msg",
  "WheelStates",
  _WheelStates__cdr_serialize,
  _WheelStates__cdr_deserialize,
  _WheelStates__get_serialized_size,
  _WheelStates__max_serialized_size
};

static rosidl_message_type_support_t _WheelStates__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_WheelStates__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace leo_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_leo_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<leo_msgs::msg::WheelStates>()
{
  return &leo_msgs::msg::typesupport_fastrtps_cpp::_WheelStates__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, leo_msgs, msg, WheelStates)() {
  return &leo_msgs::msg::typesupport_fastrtps_cpp::_WheelStates__handle;
}

#ifdef __cplusplus
}
#endif
