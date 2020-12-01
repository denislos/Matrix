#pragma once

#include <tuple>
#include <vector>
#include <ostream>
#include <istream>

namespace pagrnd {

template <typename T>
class SquareMatrix 
{
public:
    SquareMatrix() { }
    SquareMatrix(std::size_t size, T value = T{})
        : size(size)
        , data(std::vector<std::vector<T>>(size, std::vector<T>(size, value)))
    { }

    void set_row(std::size_t row_index, const std::vector<T>& row) {
        data[row_index] = row;
    }

    std::tuple<bool, SquareMatrix<T>, std::vector<std::size_t>> LUPdecompose() const;
    T det() const;

    friend std::ostream& operator<<(std::ostream& os, const SquareMatrix<T>& m) {
        for (const auto& row : m.data) {
            for (const auto elem : row)
                os << elem << " ";
            os << "\n";
        }

        return os;
    }

    friend std::istream& operator>>(std::istream& is, SquareMatrix<T>& m) {
        is >> m.size;
        m.data = std::vector<std::vector<T>>(m.size, std::vector<T>(m.size));

        for (auto& row : m.data)
            for (auto& elem : row)
                is >> elem;
        
        return is;
    }

private:
    std::size_t size = 0;
    std::vector<std::vector<T>> data;
};


} // namespace pagrnd