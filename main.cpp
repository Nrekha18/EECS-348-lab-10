#include "Matrix.h"
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter input file name: ";
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

    std::cout << "\n[1] Matrix A:\n" << A << "\nMatrix B:\n" << B;

    std::cout << "\n[2] A + B:\n" << (A + B);
    std::cout << "\n[3] A * B:\n" << (A * B);

    std::cout << "\n[4] Diagonal sums of A: main = " << A.mainDiagonalSum()
              << ", secondary = " << A.secondaryDiagonalSum() << "\n";

    std::cout << "\n[5] Swap rows of A (default 0,1):\n" << swapRows(A);
    std::cout << "\nSwap rows of A (custom 1,3):\n" << swapRows(A, 1, 3);

    std::cout << "\n[6] Swap columns of A (default 0,1):\n" << swapCols(A);
    std::cout << "\nSwap columns of A (custom 0,2):\n" << swapCols(A, 0, 2);

    std::cout << "\n[7] Update A (defaults: row 0, col 0, value 100):\n" << updateElement(A);
    std::cout << "\nUpdate A (row 2, col 3, value -7):\n" << updateElement(A, 2, 3, -7);

    std::cout << "\nOriginal A is unchanged:\n" << A;
    return 0;
}
