#include "./test.cpp"
#include "../src/matrix.h"

using std::vector;

class DecompositionTest : public ::testing::Test{};

TEST_F(DecompositionTest, First) {
    // Создаем класс матрицы
    My::Matrix<int> matrix(2);
    // Инициализируем элементы
    matrix[0] = {3, 9};
    matrix[1] = {15, 49};
    // Проводим разложение матрицы
    matrix.decomposition();

    // Проверяем результат
    ASSERT_EQ(matrix[0], vector<int>({3, 3}));
    ASSERT_EQ(matrix[1], vector<int>({5, 4}));
}

TEST_F(DecompositionTest, Second) {
    My::Matrix<int> matrix(3);

    matrix[0] = {2, 4, -6};
    matrix[1] = {-2, -8, -10};
    matrix[2] = {-6, -32, -66};
    matrix.decomposition();

    ASSERT_EQ(matrix[0], vector<int>({2, 2, -3}));
    ASSERT_EQ(matrix[1], vector<int>({-1, -4, 4}));
    ASSERT_EQ(matrix[2], vector<int>({-3, 5, -4}));
}