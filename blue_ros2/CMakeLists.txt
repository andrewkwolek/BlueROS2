cmake_minimum_required(VERSION 3.8)
project(blue_ros2)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(bluerov2_node src/bluerov2_node.cpp)
ament_target_dependencies(bluerov2_node rclcpp std_msgs)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

# # Install nodes
install(TARGETS
  bluerov2_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
