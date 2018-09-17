#include "matrix.h"

template <class Type>
My::Matrix<Type>::Matrix()
        : _size(0) {};

template <class Type>
void My::Matrix<Type>::read(std::ifstream &file) {
    file >> _size;
    _matrix.reserve(_size);

    for (int i = 0; i < _size; i++) {
        _matrix.reserve(_size);
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
const vector<Type>& My::Matrix<Type>::operator [] (int n) const {
    return _matrix[n];
}
