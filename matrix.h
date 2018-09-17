#ifndef MATRIX_H
#define MATRIX_H

#include "main.h"

using std::vector;
using std::cout;
using std::endl;

namespace My {

    template<class Type>
    using matrix = class vector<vector<Type>>;

    template<class Type>
    class Matrix {
    private:
        size_t _size;
        matrix<Type> _matrix;

    public:
        Matrix();

        /**
         * Функция нужна для чтения матрицы из файла
         * @param ifstream
         */
        void read(std::ifstream &file);

        /**
         * Функция нужна для вывода матрицы в консоль
         */
        void print() const;

        vector<Type>& operator[](int n);
    };

    template class Matrix<float>;
    template class Matrix<int>;
}
#endif // MATRIX_H
