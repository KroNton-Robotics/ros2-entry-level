cmake_minimum_required(VERSION 3.8)
project(my_first_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp  REQUIRED)
find_package(std_msgs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(a_class_base src/concepts/oop/a_class_base.cpp)
add_executable(b_class_inherit src/concepts/oop/b_class_inherit.cpp)
add_executable(a_no_bind_func src/concepts/bind/a_no_bind_func.cpp)
add_executable(b_bind_func src/concepts/bind/b_bind_func.cpp)
add_executable(c_no_bind_class src/concepts/bind/c_no_bind_class.cpp)
add_executable(d_bind_class src/concepts/bind/d_bind_class.cpp)




add_executable(simple_node src/simple_node.cpp)
ament_target_dependencies(simple_node rclcpp std_msgs) 

add_executable(simple_timer_node src/simple_timer_node.cpp)
ament_target_dependencies(simple_timer_node rclcpp std_msgs)

add_executable(simple_timer_lambda_node src/simple_timer_lambda_node.cpp)
ament_target_dependencies(simple_timer_lambda_node rclcpp std_msgs)

install(TARGETS
  a_class_base
  b_class_inherit
  a_no_bind_func
  b_bind_func
  c_no_bind_class
  d_bind_class
  simple_node
  simple_timer_node
  simple_timer_lambda_node
  DESTINATION lib/${PROJECT_NAME})


ament_package()
