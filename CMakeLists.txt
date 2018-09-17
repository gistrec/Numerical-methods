cmake_minimum_required(VERSION 3.9)
project(lab_cm_v1)

set(CMAKE_CXX_STANDARD 11)

set(ADDITIONAL_FILES
        matrix.cpp)


add_executable(lab_cm_v1 main.cpp ${ADDITIONAL_FILES})