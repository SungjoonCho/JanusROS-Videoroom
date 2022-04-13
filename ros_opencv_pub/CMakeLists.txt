cmake_minimum_required(VERSION 3.0.2)
project(ros_opencv_pub)

## Compile as C++11, supported in ROS Kinetic and newer
 add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
)

find_package(OpenCV REQUIRED)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

 catkin_package(
 #  INCLUDE_DIRS include
 #  LIBRARIES ros_opencv_sub
 #  CATKIN_DEPENDS cv_bridge image_transport roscpp
 #  DEPENDS system_lib
 )


###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
 include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(ros_opencv_pub ros_opencv_pub.cpp)
target_link_libraries(ros_opencv_pub ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
