cmake_minimum_required(VERSION 3.13.1)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/Arduino-Toolchain.cmake)
set(ARDUINO_CMAKE_SKETCHBOOK_PATH ${CMAKE_SOURCE_DIR}/../..)

project(DcsBiosMcpLibrary)

get_board_id(uno_board_id uno)

set(dcsbios_servo_sources src/DcsBiosServo.h src/controls/ServoControl.cpp)
add_arduino_library(dcsbios_servo_uno_lib ${uno_board_id} ${dcsbios_servo_sources})
add_arduino_core_lib(dcsbios_servo_uno_lib ${uno_board_id})

find_arduino_library(dcsbios_uno_lib DcsBios ${uno_board_id} 3RD_PARTY)
link_arduino_library(dcsbios_servo_uno_lib dcsbios_uno_lib ${uno_board_id})

find_arduino_library(servo_lib Servo ${uno_board_id})
link_arduino_library(dcsbios_servo_uno_lib servo_lib ${uno_board_id})