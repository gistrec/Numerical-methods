cmake_minimum_required(VERSION 3.9)
project(lab_cm_v1)

set(CMAKE_CXX_STANDARD 11)

set(ADDITIONAL_FILES
        src/matrix.cpp
        src/main.cpp)


add_executable(lab_cm_v1 ${ADDITIONAL_FILES})