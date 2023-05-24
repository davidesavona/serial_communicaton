cmake_minimum_required(VERSION 3.5)

project(arduino-communication LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(third-party/include)

set(serial_SRCS serial.cc serial.h 
    v8stdint.h list_ports_linux.cc
    motor.h)
list(APPEND serial_SRCS unix.cc)

add_library(serial ${serial_SRCS})
target_link_libraries(serial )

add_executable(arduino-communication test.cpp motor.cpp motor.h)
target_link_libraries(arduino-communication serial)
