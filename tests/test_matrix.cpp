#include <gtest/gtest.h>

#include <sstream>

#include "square_matrix.h"

TEST(SquareMatrixTest, DefaultConstructor)
{
    pagrnd::SquareMatrix<double> matrix;
}

TEST(SquareMatrixTest, Determinant2x2)
{
    std::istringstream iss(
        "2\n"
        "4 2\n"
        "3 2\n"
    );

    pagrnd::SquareMatrix<double> matrix;
    iss >> matrix;

    const auto determinant = matrix.det();
    ASSERT_EQ(determinant, 2);
}

TEST(SquareMatrixTest, Determinant3x3)
{
    std::istringstream iss(
        "3\n"
        "2 3 1\n"
        "6 5 2\n"
        "1 4 7\n"
    );

    pagrnd::SquareMatrix<double> matrix;
    iss >> matrix;

    const auto determinant = matrix.det();
    ASSERT_EQ(determinant, -47);
}

TEST(SquareMatrixTest, Determinant3x3Deg)
{
    std::istringstream iss(
        "3\n"
        "1 0 0\n"
        "3 0 0\n"
        "1 4 7\n"
    );

    pagrnd::SquareMatrix<double> matrix;
    iss >> matrix;

    const auto determinant = matrix.det();
    ASSERT_EQ(determinant, 0);
}

TEST(SquareMatrixTest, Determinant4x4Ones)
{
    std::istringstream iss(
        "4\n"
        "1 0 0 0\n"
        "0 1 0 0\n"
        "0 0 1 0\n"
        "0 0 0 1\n"
    );

    pagrnd::SquareMatrix<double> matrix;
    iss >> matrix;

    const auto determinant = matrix.det();
    ASSERT_EQ(determinant, 1);
}

TEST(SquareMatrixTest, Determinant5x5Deg)
{
    std::istringstream iss(
        "5\n"
        "1 3 1 -6 8\n"
        "-1 2 -1 6 -8\n"
        "0 0 4 8 -4\n"
        "2 6 0 -16 18\n"
        "0 0 1 2 2\n"
    );

    pagrnd::SquareMatrix<double> matrix;
    iss >> matrix;

    const auto determinant = matrix.det();
    std::cout << determinant;
    ASSERT_EQ(determinant, 0);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}