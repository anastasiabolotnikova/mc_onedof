# Here we find a typical ROS description package, this set the JVRC_DESCRIPTION_PATH CMake variable
find_description_package(onedof_description)
# Generate the robot module C++ code using this value
configure_file(OneDoFRobotModule.in.cpp "${CMAKE_CURRENT_BINARY_DIR}/OneDoFRobotModule.cpp")

set(module_SRC
  "${CMAKE_CURRENT_BINARY_DIR}/OneDoFRobotModule.cpp"
)

set(module_HDR
  OneDoFRobotModule.h
)

add_robot(OneDoFRobotModule "${module_SRC}" "${module_HDR}")
target_include_directories(OneDoFRobotModule PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
