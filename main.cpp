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

int main() {
    std::ifstream file("input.txt");
    My::Matrix<int>* m = new My::Matrix<int>();
    m->read(file);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}