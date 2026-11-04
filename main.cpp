#include "Matrix.h"
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter input filename: ";
    std::cin >> filename;

    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "Error: cannot open " << filename << "\n";
        return 1;
    }

    Matrix A, B;
    if (!Matrix::readTwo(fin, A, B)) {
        std::cerr << "Error: invalid file format.\n";
        return 1;
    }

    // Practice 1: display both matrices
    std::cout << "Matrix A:\n" << A << "\nMatrix B:\n" << B;

    // Practice 2: addition via operator+
    std::cout << "\nA + B:\n" << (A + B);

    // Practice 3: multiplication via operator*
    std::cout << "\nA * B:\n" << (A * B);

    // Practice 4: diagonal sums
    std::cout << "\nDiagonal sums for Matrix A:\n"
              << "Main diagonal sum: " << A.mainDiagonalSum() << "\n"
              << "Secondary diagonal sum: " << A.secondaryDiagonalSum() << "\n";

    // Practice 5: swap rows 0 and 2 (A itself is not modified)
    std::cout << "\nProblem 5 - Rows 0 and 2 swapped:\n" << swapRows(A, 0, 2);

    // Practice 6: swap columns 0 and 2
    std::cout << "\nProblem 6 - Columns 0 and 2 swapped:\n" << swapCols(A, 0, 2);

    // Practice 7: update row 1, column 2 to 99
    std::cout << "\nProblem 7 - Updated matrix:\n" << updateElement(A, 1, 2, 99);

    return 0;
}
