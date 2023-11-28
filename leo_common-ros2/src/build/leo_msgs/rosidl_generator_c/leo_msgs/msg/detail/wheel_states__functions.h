// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from leo_msgs:msg/WheelStates.idl
// generated code does not contain a copyright notice

#ifndef LEO_MSGS__MSG__DETAIL__WHEEL_STATES__FUNCTIONS_H_
#define LEO_MSGS__MSG__DETAIL__WHEEL_STATES__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "leo_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "leo_msgs/msg/detail/wheel_states__struct.h"

/// Initialize msg/WheelStates message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * leo_msgs__msg__WheelStates
 * )) before or use
 * leo_msgs__msg__WheelStates__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_leo_msgs
bool
leo_msgs__msg__WheelStates__init(leo_msgs__msg__WheelStates * msg);

/// Finalize msg/WheelStates message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_leo_msgs
void
leo_msgs__msg__WheelStates__fini(leo_msgs__msg__WheelStates * msg);

/// Create msg/WheelStates message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * leo_msgs__msg__WheelStates__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_leo_msgs
leo_msgs__msg__WheelStates *
leo_msgs__msg__WheelStates__create();

/// Destroy msg/WheelStates message.
/**
 * It calls
 * leo_msgs__msg__WheelStates__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_leo_msgs
void
leo_msgs__msg__WheelStates__destroy(leo_msgs__msg__WheelStates * msg);

/// Check for msg/WheelStates message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_leo_msgs
bool
leo_msgs__msg__WheelStates__are_equal(const leo_msgs__msg__WheelStates * lhs, const leo_msgs__msg__WheelStates * rhs);

/// Copy a msg/WheelStates message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_leo_msgs
bool
leo_msgs__msg__WheelStates__copy(
  const leo_msgs__msg__WheelStates * input,
  leo_msgs__msg__WheelStates * output);

/// Initialize array of msg/WheelStates messages.
/**
 * It allocates the memory for the number of elements and calls
 * leo_msgs__msg__WheelStates__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_leo_msgs
bool
leo_msgs__msg__WheelStates__Sequence__init(leo_msgs__msg__WheelStates__Sequence * array, size_t size);

/// Finalize array of msg/WheelStates messages.
/**
 * It calls
 * leo_msgs__msg__WheelStates__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_leo_msgs
void
leo_msgs__msg__WheelStates__Sequence__fini(leo_msgs__msg__WheelStates__Sequence * array);

/// Create array of msg/WheelStates messages.
/**
 * It allocates the memory for the array and calls
 * leo_msgs__msg__WheelStates__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_leo_msgs
leo_msgs__msg__WheelStates__Sequence *
leo_msgs__msg__WheelStates__Sequence__create(size_t size);

/// Destroy array of msg/WheelStates messages.
/**
 * It calls
 * leo_msgs__msg__WheelStates__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_leo_msgs
void
leo_msgs__msg__WheelStates__Sequence__destroy(leo_msgs__msg__WheelStates__Sequence * array);

/// Check for msg/WheelStates message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_leo_msgs
bool
leo_msgs__msg__WheelStates__Sequence__are_equal(const leo_msgs__msg__WheelStates__Sequence * lhs, const leo_msgs__msg__WheelStates__Sequence * rhs);

/// Copy an array of msg/WheelStates messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_leo_msgs
bool
leo_msgs__msg__WheelStates__Sequence__copy(
  const leo_msgs__msg__WheelStates__Sequence * input,
  leo_msgs__msg__WheelStates__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // LEO_MSGS__MSG__DETAIL__WHEEL_STATES__FUNCTIONS_H_
