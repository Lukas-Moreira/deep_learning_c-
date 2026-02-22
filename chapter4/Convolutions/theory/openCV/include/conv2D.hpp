#pragma once

#include <iostream>
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>

using std::cout;
using std::endl;
using Matrix = Eigen::MatrixXd;
using namespace cv;

/**
 * @brief Performs a 2D convolution between an input matrix and a kernel matrix.
 * 
 * Although this implementation working, it is not correctly because it not adding the 
 * padding to the input matrix, so the output is smaller than the input. 
 * To fix this, we need to add padding to the input matrix before performing the convolution.
 */
auto conv2D = [](const Matrix& input, const Matrix& kernel) {
    int outputRows = input.rows() - kernel.rows() + 1;
    int outputCols = input.cols() - kernel.cols() + 1;

    Matrix output = Matrix::Zero(outputRows, outputCols);

    for (int i = 0; i < outputRows; ++i) {
        for (int j = 0; j < outputCols; ++j) {
            double sum = input.block(i,j, kernel.rows(), kernel.cols()).cwiseProduct(kernel).sum();
            output(i, j) = sum;
        }
    }

    return output;
};

/**
 * @brief In this implementation, we add padding to the input matrix before performing the convolution.
 * 
 * This approach is memory-inefficient because it creates a zero-padded matrix and copies the input.
 * A more optimized version would check boundary conditions during convolution to avoid explicit padding.
 */
auto conv2D_Padded = [](const Matrix& input, const Matrix& kernel, int padding) {
    int outputRows = input.rows() - kernel.rows() + 2*padding + 1;
    int outputCols = input.cols() - kernel.cols() + 2*padding + 1;

    // Create a padded version of the input matrix
    Matrix paddedInput = Matrix::Zero(input.rows() + 2*padding, input.cols() + 2*padding);
    paddedInput.block(padding, padding, input.rows(), input.cols()) = input; // -> copy input into the center of the padded matrix
    
    Matrix output = Matrix::Zero(outputRows, outputCols);

    for (int i = 0; i < outputRows; ++i) {
        for (int j = 0; j < outputCols; ++j) {
            double sum = paddedInput.block(i,j, kernel.rows(), kernel.cols()).cwiseProduct(kernel).sum();
            output(i, j) = sum;
        }
    }

    return output;
};

/**
 * @brief Optimized 2D convolution that uses Region of Interest (ROI) instead of explicit padding.
 * 
 * This approach is more memory-efficient as it avoids creating a padded matrix.
 * Instead, it checks boundary conditions during convolution and only processes
 * the relevant parts of the kernel and input, effectively handling padding implicitly.
 * 
 * @references
 * - Carlos d'Oleron, Luiz. 
 *   "Deep Learning in Modern C++: End-to-end development and implementation of deep learning algorithms.
 */
auto conv2D_Optimizer = [](const Matrix& input, const Matrix& kernel, int padding) {
    int I_rows = input.rows();
    int I_cols = input.cols();
    int K_rows = kernel.rows();
    int K_cols = kernel.cols();

    if (I_rows < K_rows || I_cols < K_cols) {
        throw std::invalid_argument("Kernel size must be smaller than or equal to input size.");
    }

    // Get dimensions of the output matrix
    const int rows = I_rows - K_rows + 2*padding + 1;
    const int cols = I_cols - K_cols + 2*padding + 1;

    // Lambda function to calculate the fitting dimensions for the input and kernel based on the 
    // current position and padding
    auto fitting_dims = [&padding](int position, int k, int length){
        int input = position - padding;     
        int kernel = 0;                     
        int size = k;                       

        if (input < 0) {
            kernel = -input;    
            size   += input;
            input  = 0;
        }

        if (input + size > length){
            size = length - input;
        }

        return std::make_tuple(input, kernel, size);
    };


    Matrix output = Matrix::Zero(rows, cols);

    for (int i = 0; i < rows; ++i) {
        const auto [input_i, kernel_i, size_i] = fitting_dims(i, K_rows, I_rows);
        for (int j = 0; j < cols; ++j) {
            const auto [input_j, kernel_j, size_j] = fitting_dims(j, K_cols, I_cols);
            if (size_i > 0 && size_j > 0) {
                auto input_roi = input.block(input_i, input_j, size_i, size_j);
                auto kernel_roi = kernel.block(kernel_i, kernel_j, size_i, size_j);
                output(i, j) = (input_roi.cwiseProduct(kernel_roi)).sum();
            }
        }
    }

    return output;
};