cmake_minimum_required(VERSION 3.2)
project(patrol_line)

find_package(OpenCV)

include_directories(include)
aux_source_directory(src DIR_SRCS)

add_executable(code ${DIR_SRCS})
target_link_libraries(code ${OpenCV_LIBS})

