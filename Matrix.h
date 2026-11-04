#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>
#include <vector>

// Square N x N matrix. All data is private; access goes through public members.
class Matrix {
private:
    int size;
    std::vector<int> data;  // row-major storage, hidden from users of the class

public:
    Matrix(int n = 0);

    int getSize() const { return size; }
    int get(int r, int c) const { return data[r * size + c]; }
    void set(int r, int c, int value) { data[r * size + c] = value; }
    bool validIndex(int i) const { return i >= 0 && i < size; }

    // Reads N from the stream, then two N x N matrices (Practice 1).
    static bool readTwo(std::istream& in, Matrix& a, Matrix& b);
    void readValues(std::istream& in);

    // Practice 2 and 3: operator overloading.
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    // Practice 4
    int mainDiagonalSum() const;
    int secondaryDiagonalSum() const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
};

// Practices 5-7: Matrix is passed BY VALUE so the caller's matrix is untouched.
Matrix swapRows(Matrix m, int r1 = 0, int r2 = 1);
Matrix swapCols(Matrix m, int c1 = 0, int c2 = 1);
Matrix updateElement(Matrix m, int row = 0, int col = 0, int value = 100);

#endif
