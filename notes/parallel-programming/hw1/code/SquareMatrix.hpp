#ifndef SQUARE_MATRIX_HPP
#define SQUARE_MATRIX_HPP

#include <vector>
#include <cstddef>

class SquareMatrixView;

class SquareMatrix
{
public:
    SquareMatrix(size_t n);
    SquareMatrix(std::vector<std::vector<double>> const &data);
    SquareMatrix(std::vector<std::vector<double>> &&data);
    SquareMatrix(std::initializer_list<std::initializer_list<double>> data);
    
    auto at(size_t i, size_t j) -> double &;
    auto at(size_t i, size_t j) const -> double const &;
    auto write_submat(size_t i, size_t j, SquareMatrixView const &submat) -> void;
    auto write(size_t i, size_t j, double value) -> void;

    operator SquareMatrixView();
    operator SquareMatrixView() const;

private:
    std::vector<std::vector<double>> data;
};

#endif // SQUARE_MATRIX_HPP
