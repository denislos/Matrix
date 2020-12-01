
#include "square_matrix.h"

namespace pagrnd {

template <typename T>
std::tuple<bool, SquareMatrix<T>, std::vector<std::size_t>> SquareMatrix<T>::LUPdecompose() const
{
    std::vector<std::size_t> P(size + 1);
    for (std::size_t i = 0; i <= size; ++i)
        P[i] = i;

    T maxEl, absV;
    std::size_t i, j, k, maxInd;

    SquareMatrix<T> A = *this;

    for (i = 0; i < size; ++i)
    {
        maxEl = static_cast<T>(0);
        maxInd = i;

        for (k = i; k < size; ++k)
            if ((absV = std::abs(A.data[k][i])) > maxEl)
            {
                maxEl = absV;
                maxInd = k;
            }
        
        // tolerance
        if (maxEl < 0.00000000000001)
            return std::make_tuple(false, A, P);

        if (maxInd != i)
        {
            std::swap(P[i], P[maxInd]);
            std::swap(A.data[i], A.data[maxInd]);

            P[size]++;            
        }

        for (j = i + 1; j < size; ++j)
        {
            A.data[j][i] /= A.data[i][i];

            for (k = i + 1; k < size; ++k)
                A.data[j][k] -= A.data[j][i] * A.data[i][k];
        }
    }

    return std::make_tuple(true, A, P);
}

template <typename T>
T SquareMatrix<T>::det() const
{
    auto [not_degenerate, A, P] = LUPdecompose();

    if (!not_degenerate)
        return 0;

    T  determinant = A.data[0][0];
    for (std::size_t i = 1; i < size; ++i)
        determinant *= A.data[i][i];
    
    return (P[size] - size) % 2 == 0 ? determinant : -determinant;
}

template class SquareMatrix<double>;
template class SquareMatrix<float>;

} // namespace pagrnd