#include <vector>
#include <cassert>
#include <iostream>

#include "SquareMatrix.hpp"
#include "SquareMatrixView.hpp"

auto lower_triangular_inverse(SquareMatrixView const &matrix, size_t multithread_threshold = 2) 
    -> SquareMatrix;

auto test_lower_triangular_inverse(SquareMatrixView const &A) {
    auto const n = A.size();
    auto const A_inv = lower_triangular_inverse(A);
    auto const I = A * A_inv;
    auto success = true;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i == j) {
                success &= I.at(i, j) == 1;
            } else {
                success &= I.at(i, j) == 0;
            }
        }
    }

    if (!success) {
        std::cout << "Test failed\n"
            << "Test case: A =\n" << A << "\n"
            << "Expected identity, got:\n"
            << I << std::endl;
    } else {
        std::cout << "Test passed" << std::endl;
    }
}

int main() {
    auto const tests = std::vector<SquareMatrix> {
        {
            {1, 0, 0, 0},
            {-1, 1, 0, 0},
            {-1, -1, 1, 0},
            {-1, -1, -1, 1},
        },
        {
            {1, 0, 0, 0},
            {-1, 1, 0, 0},
            {1, -1, 1, 0},
            {1, 1, -1, 1},
        },
        {
            {1, 0, 0, 0},
            {1, 1, 0, 0},
            {1, 1, 1, 0},
            {1, 1, 1, 1},
        }
    };

    for (auto const &test : tests) {
        test_lower_triangular_inverse(test);
    }
}