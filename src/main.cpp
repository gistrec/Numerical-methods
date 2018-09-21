#include "main.h"

int main() {
    std::ifstream file("../inputs/input.txt", std::fstream::in);
    My::Matrix<float> matrix;
    matrix.read(file);
    matrix.print();

    // Получаем LDU разложение
    matrix.decomposition();
    matrix.print();

    std::cout << "It's work!" << std::endl;
    return 0;
}

