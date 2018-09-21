#ifndef MAIN_H
#define MAIN_H

#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert> // assert()

#include "./decomposition.cpp"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif // MAIN_H