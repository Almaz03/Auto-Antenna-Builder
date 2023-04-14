cmake_minimum_required(VERSION 3.23)
project(Auto-Antenna-Builder)

set(CMAKE_CXX_STANDARD 14)

add_executable(Auto-Antenna-Builder Source/autoantenna.cpp Source/classes.h Source/initialization.h Source/functions.h Source/import_data.h Source/export_data.h Source/modules/functions.cpp Source/modules/initialization.cpp Source/modules/import_data.cpp Source/modules/classes.cpp Source/modules/export_data.cpp)
