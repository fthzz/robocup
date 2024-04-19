cmake_minimum_required(VERSION 3.2)
project(patrol_line)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV)

include_directories(include)
aux_source_directory(src DIR_SRCS)

add_executable(code ${DIR_SRCS})
target_link_libraries(code ${OpenCV_LIBS})

