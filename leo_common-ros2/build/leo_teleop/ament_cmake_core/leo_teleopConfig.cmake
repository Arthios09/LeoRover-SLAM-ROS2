# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_leo_teleop_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED leo_teleop_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(leo_teleop_FOUND FALSE)
  elseif(NOT leo_teleop_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(leo_teleop_FOUND FALSE)
  endif()
  return()
endif()
set(_leo_teleop_CONFIG_INCLUDED TRUE)

# output package information
if(NOT leo_teleop_FIND_QUIETLY)
  message(STATUS "Found leo_teleop: 1.1.0 (${leo_teleop_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'leo_teleop' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${leo_teleop_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(leo_teleop_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${leo_teleop_DIR}/${_extra}")
endforeach()
