cmake_minimum_required(VERSION 3.10) # specify the minimum version of cmake to run

project(zeromq-cpp) # name of the project

set(CMAKE_CXX_STANDARD 17) # which c++ version to use

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(server server.cpp) # the exeexecutable name
add_executable(worker worker.cpp) # the exeexecutable name

target_link_libraries(server zmq)
target_link_libraries(worker zmq)

#################
# zeromq #
#################
#find_package(cppzmq)
#target_link_libraries(${PROJECT_NAME} cppzmq)
