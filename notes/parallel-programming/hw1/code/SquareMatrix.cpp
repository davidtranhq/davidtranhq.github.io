#include "SquareMatrix.hpp"
#include "SquareMatrixView.hpp"

SquareMatrix::SquareMatrix(size_t n) : data(n, std::vector<double>(n)) {}

SquareMatrix::SquareMatrix(std::vector<std::vector<double>> const &data) : data(data) {}

SquareMatrix::SquareMatrix(std::vector<std::vector<double>> &&data) : data(std::move(data)) {}

SquareMatrix::SquareMatrix(std::initializer_list<std::initializer_list<double>> data) {
    for (auto const &row : data) {
        this->data.emplace_back(row);
    }
}

auto SquareMatrix::at(size_t i, size_t j) -> double & {
    return data[i][j];
}

auto SquareMatrix::at(size_t i, size_t j) const -> double const & {
    return data[i][j];
}

auto SquareMatrix::write_submat(size_t i, size_t j, SquareMatrixView const &submat) -> void{
    for (size_t row = 0; row < submat.size(); ++row) {
        for (size_t col = 0; col < submat.size(); ++col) {
            data[i + row][j + col] = submat.at(row, col);
        }
    }
}

SquareMatrix::operator SquareMatrixView() {
    return SquareMatrixView {*this, 0, 0, data.size()};
}

SquareMatrix::operator SquareMatrixView() const {
    return SquareMatrixView {const_cast<SquareMatrix &>(*this), 0, 0, data.size()};
}