cmake_minimum_required(VERSION 3.10)

# Set the project name
project(video_to_ascii)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Add the executable
add_executable(video_to_ascii main.cpp)

# Link OpenCV libraries
target_link_libraries(video_to_ascii ${OpenCV_LIBS})