cmake_minimum_required(VERSION 2.8)
project( encryption )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( encryption main.cpp )
target_link_libraries( encryption ${OpenCV_LIBS} )