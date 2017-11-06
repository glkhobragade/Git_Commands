cmake_minimum_required(VERSION 3.5)

project(image_tools)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(OpenCV REQUIRED)

include_directories("/usr/include")
link_directories("/usr/lib/x86_64-linux-gnu")
add_executable(display_image display_image.cpp)
add_executable(display_camera display_camera.cpp)
add_executable(display_camera2 display_camera2.cpp)
add_executable(write_video write_video.cpp)
add_executable(image_shades image_shades.cpp)
add_executable(blank_image blank_image.cpp)

target_link_libraries(display_image opencv_highgui opencv_core opencv_imgcodecs)
target_link_libraries(display_camera opencv_highgui opencv_core opencv_imgcodecs opencv_objdetect opencv_imgproc)
target_link_libraries(display_camera2 opencv_highgui opencv_core opencv_imgcodecs opencv_objdetect opencv_imgproc)
target_link_libraries(write_video opencv_highgui opencv_core opencv_imgcodecs opencv_objdetect opencv_imgproc)
target_link_libraries(image_shades opencv_highgui opencv_core opencv_imgcodecs opencv_objdetect opencv_imgproc)
target_link_libraries(blank_image opencv_highgui opencv_core opencv_imgcodecs opencv_objdetect opencv_imgproc)

