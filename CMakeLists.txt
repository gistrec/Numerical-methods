cmake_minimum_required(VERSION 3.9)
project(lab_cm_v1)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_executable(lab_cm_v1 src/main.cpp src/matrix.cpp)


add_executable(run_tests tests/test.cpp src/matrix.cpp)
target_link_libraries(run_tests ${GTEST_LIBRARIES} Threads::Threads)
enable_testing()
add_test(run_tests tests/test.cpp)