
#include <iostream>
#include <cstdlib>

#include "square_matrix.h"


int main()
{
    pagrnd::SquareMatrix<double> matrix;
    std::cin >> matrix;

    const auto determinant = matrix.det();
    std::cout << "Determinant: " << determinant << "\n";

    return EXIT_SUCCESS;
}