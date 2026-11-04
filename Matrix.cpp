#include "Matrix.h"
#include <algorithm>
#include <iomanip>

Matrix::Matrix(int n) : size(n), data(static_cast<size_t>(n) * n, 0) {}

void Matrix::readValues(std::istream& in) {
    for (int i = 0; i < size * size; ++i) in >> data[i];
}

bool Matrix::readTwo(std::istream& in, Matrix& a, Matrix& b) {
    int n;
    if (!(in >> n) || n <= 0) return false;
    a = Matrix(n);
    b = Matrix(n);
    a.readValues(in);
    b.readValues(in);
    return static_cast<bool>(in);
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(size);
    for (int i = 0; i < size * size; ++i)
        result.data[i] = data[i] + other.data[i];
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            int sum = 0;
            for (int k = 0; k < size; ++k) sum += get(i, k) * other.get(k, j);
            result.set(i, j, sum);
        }
    return result;
}

int Matrix::mainDiagonalSum() const {
    int sum = 0;
    for (int i = 0; i < size; ++i) sum += get(i, i);
    return sum;
}

int Matrix::secondaryDiagonalSum() const {
    int sum = 0;
    for (int i = 0; i < size; ++i) sum += get(i, size - 1 - i);
    return sum;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    size_t width = 4;  // widest entry + 1 space, minimum width 4, so columns line up
    for (int v : m.data) width = std::max(width, std::to_string(v).size() + 1);
    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j)
            os << std::setw(static_cast<int>(width)) << m.get(i, j);
        os << '\n';
    }
    return os;
}

Matrix swapRows(Matrix m, int r1, int r2) {
    if (!m.validIndex(r1) || !m.validIndex(r2)) {
        std::cout << "Invalid row index; matrix unchanged.\n";
        return m;
    }
    for (int j = 0; j < m.getSize(); ++j) {
        int tmp = m.get(r1, j);
        m.set(r1, j, m.get(r2, j));
        m.set(r2, j, tmp);
    }
    return m;
}

Matrix swapCols(Matrix m, int c1, int c2) {
    if (!m.validIndex(c1) || !m.validIndex(c2)) {
        std::cout << "Invalid column index; matrix unchanged.\n";
        return m;
    }
    for (int i = 0; i < m.getSize(); ++i) {
        int tmp = m.get(i, c1);
        m.set(i, c1, m.get(i, c2));
        m.set(i, c2, tmp);
    }
    return m;
}

Matrix updateElement(Matrix m, int row, int col, int value) {
    if (!m.validIndex(row) || !m.validIndex(col)) {
        std::cout << "Invalid row/column index; matrix unchanged.\n";
        return m;
    }
    m.set(row, col, value);
    return m;
}