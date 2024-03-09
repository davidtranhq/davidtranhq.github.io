#include <iostream>
#include <iomanip>
#include "SquareMatrixView.hpp"
#include "SquareMatrix.hpp"

SquareMatrixView::SquareMatrixView(SquareMatrix &matrix, size_t i, size_t j, size_t n)
    : matrix {matrix},
      row_offset {i},
      col_offset {j},
      order {n}
{}

auto SquareMatrixView::at(size_t i, size_t j) -> double & {
    return matrix.at(i + row_offset, j + col_offset);
}

auto SquareMatrixView::at(size_t i, size_t j) const -> double const & {
    return matrix.at(i + row_offset, j + col_offset);
}

auto SquareMatrixView::size() const -> size_t {
    return order;
}

auto SquareMatrixView::inverse_forward_substitution() const -> SquareMatrix {
    auto result = SquareMatrix {order};
    for (size_t i = 0; i < order; ++i) {
        result.at(i, i) = 1 / at(i, i);
        for (size_t j = i + 1; j < order; ++j) {
            double sum = 0;
            for (size_t k = i; k < j; ++k) {
                sum -= at(j, k) * result.at(k, i);
            }
            result.at(j, i) = sum / at(j, j);
        }
    }
    return result;
}

auto SquareMatrixView::submat(size_t row, size_t col, size_t n) const -> SquareMatrixView {
    return SquareMatrixView {matrix, row + row_offset, col + col_offset, n};
}

auto operator+(SquareMatrixView const &lhs, SquareMatrixView const &rhs) -> SquareMatrix {
    auto result = SquareMatrix {lhs.size()};
    for (size_t i = 0; i < lhs.size(); ++i) {
        for (size_t j = 0; j < lhs.size(); ++j) {
            result.at(i, j) = lhs.at(i, j) + rhs.at(i, j);
        }
    }
    return result;
}

auto operator*(SquareMatrixView const &lhs, SquareMatrixView const &rhs) -> SquareMatrix {
    auto result = SquareMatrix {lhs.size()};
    for (size_t i = 0; i < lhs.size(); ++i) {
        for (size_t j = 0; j < lhs.size(); ++j) {
            double sum = 0;
            for (size_t k = 0; k < lhs.size(); ++k) {
                sum += lhs.at(i, k) * rhs.at(k, j);
            }
            result.at(i, j) = sum;
        }
    }
    return result;
}

auto operator-(SquareMatrixView const &unary) -> SquareMatrix {
    auto result = SquareMatrix {unary.size()};
    for (size_t i = 0; i < unary.size(); ++i) {
        for (size_t j = 0; j < unary.size(); ++j) {
            result.at(i, j) = -unary.at(i, j);
        }
    }
    return result;
}

auto operator<<(std::ostream &os, SquareMatrixView const &m) -> std::ostream & {
    for (size_t i = 0; i < m.size(); ++i) {
        for (size_t j = 0; j < m.size(); ++j) {
            os << std::fixed << std::setw(10) << std::setprecision(20) << m.at(i, j);
        }
        os << std::endl;
    }
    return os;
}