#include "main.h"

// Задачи:
// 1. Разработать программу решения СЛАУ прямым методом с хранением матрицы в профильном или ленточном формате.
// 2. Исследовать накопление погрешности и ее зависимость от числа обусловленности.
// 3. Сравнить реализованный метод по точности получаемого решения и количеству действий с методом Гаусса.
//
// Вариант 10
// LU - разложение, матрица в профильном формате, где
//
// L - нижнетреугольная матрица с 1 на диагонали
// U - верхнетреугольная матрица с 1 на диагонали
//
// Матрица в профильном  формате

/*matrix A = {{2, 4, 6}, {-2, -8, -10}, {-6, -32, -66}};

matrix L = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
matrix D = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
matrix U = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

float getL(int i, int j) {
    float result = A[i][j];
    for (int k = 0; k < j; k++) {
        result -= L[j][k] * D[k][k] * U[k][j];
    }
    return result / D[j][j];
}

float getD(int i) {
    float result = A[i][i];
    for (int k = 0; k < i; k++) {
        result -= L[i][k] * D[k][k] * U[k][i];
    }
    return result;
}

float getU(int i, int j) {
    float result = A[i][j];
    for (int k = 0; k < i; k++) {
        result -= L[i][k] * D[k][k] * U[k][i];
    }
    return result / D[i][i];
}


void customPrint(matrix &m) {
    for (auto row : m) {
        for (auto var : row) {
            std::cout << var << " ";
        }
        std::cout << std::endl;
    }
}

void run() {
    for (int n = 0; n < 3; n++) {
        // Диагональка
        D[n][n] = getD(n);
        for (int i = n; i < 3; i++) {
            L[i][n] = getL(i, n);
            U[n][i] = getU(n, i);
        }
    }

    customPrint(L);
    customPrint(D);
    customPrint(U);
}*/

/**
 * Функция нужна для декомпозиции матрицы на LDU
 */
template <typename Type>
My::Matrix<Type>* result(My::Matrix<Type> &matrix) {
    My::Matrix<int> res(matrix.size());

    for (int i = 0; i < matrix.size(); i++) {
        // 1. Находим D
        // Для этого нужно просто пройтись по диагонали
        Type D = matrix[i][i];
        for (int k = 0; k < i; k++) {
            D -= res[i][k] * res[k][k] * res[k][i];
        }
        res[i][i] = D;

        // 2. Находим U и L
        // Для этого нужно пройтись по всей строке/столбцу
        for (int row = i + 1; row < matrix.size(); row++) {
            Type U = matrix[i][row];
            Type L = matrix[row][i];
            for (int k = 0; k < i; k++) {
                U -= res[i][k] * res[k][k] * res[k][row];
                L -= res[k][i] * res[k][k] * res[row][k];
            }
            res[i][row] = U / res[i][i];
            res[row][i] = L / res[i][i];
        }
    }
    res.print();
}

int main() {
    std::ifstream file("../inputs/input.txt", std::fstream::in);
    My::Matrix<float> matrix;
    matrix.read(file);
    matrix.print();
    // NOTE: элементы считаются с нуля
    result(matrix);

    std::cout << "It's work!" << std::endl;
    return 0;
}
