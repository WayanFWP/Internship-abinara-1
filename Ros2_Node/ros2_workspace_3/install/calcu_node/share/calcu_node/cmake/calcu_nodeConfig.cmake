# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_calcu_node_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED calcu_node_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(calcu_node_FOUND FALSE)
  elseif(NOT calcu_node_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(calcu_node_FOUND FALSE)
  endif()
  return()
endif()
set(_calcu_node_CONFIG_INCLUDED TRUE)

# output package information
if(NOT calcu_node_FIND_QUIETLY)
  message(STATUS "Found calcu_node: 0.0.0 (${calcu_node_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'calcu_node' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${calcu_node_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(calcu_node_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${calcu_node_DIR}/${_extra}")
endforeach()
