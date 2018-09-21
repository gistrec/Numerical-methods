#include "matrix.h"

template <class Type>
My::Matrix<Type>::Matrix(size_t size)
        : _size(size) {
    // Инициализация вектора
    _matrix.resize(_size);

    for (int i = 0; i < _size; i++) {
        _matrix[i].resize(_size);
        for (int j = 0; j < _size; j++) {
            _matrix[i][j] = 0;
        }
    }
};

template <class Type>
void My::Matrix<Type>::read(std::ifstream &file) {
    assert(file.is_open() && !file.fail());

    file >> _size;
    _matrix.resize(_size);

    for (int i = 0; i < _size; i++) {
        _matrix[i].resize(_size);
        for (int j = 0; j < _size; j++) {
            file >> _matrix[i][j];
        }
    }
}

template <class Type>
void My::Matrix<Type>::print() const {
    for (auto row : _matrix) {
        for (auto column: row) {
            cout << column << " ";
        }
        cout << endl;
    }
}

template <class Type>
size_t My::Matrix<Type>::size() const {
    return _matrix.size();
}

template <class Type>
vector<Type>& My::Matrix<Type>::operator [] (int n) {
    return _matrix[n];
}

template <typename Type>
void My::Matrix<Type>::decomposition() {
    for (int i = 0; i < _matrix.size(); i++) {
        // 1. Находим D
        // Для этого нужно просто пройтись по диагонали
        Type D = _matrix[i][i];
        for (int k = 0; k < i; k++) {
            D -= _matrix[i][k] * _matrix[k][k] * _matrix[k][i];
        }
        _matrix[i][i] = D;

        // 2. Находим U и L
        // Для этого нужно пройтись по всей строке/столбцу
        for (int row = i + 1; row < _matrix.size(); row++) {
            Type U = _matrix[i][row];
            Type L = _matrix[row][i];
            for (int k = 0; k < i; k++) {
                U -= _matrix[i][k] * _matrix[k][k] * _matrix[k][row];
                L -= _matrix[k][i] * _matrix[k][k] * _matrix[row][k];
            }
            _matrix[i][row] = U / _matrix[i][i];
            _matrix[row][i] = L / _matrix[i][i];
        }
    }
}
