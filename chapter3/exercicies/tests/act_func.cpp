#include "gtest/gtest.h"
#include "../headers/activation_functions.hpp"

TEST(SigmoidTest, ZeroInput) {
    double input = 0.0;
    double expected_output = 0.5;
    
    EXPECT_NEAR(Sigmoid(input), expected_output, 1e-9) << "Sigmoid function failed for zero input.";
}

TEST(SigmoidTest, PositiveInput) {
    double input = 45.0;
    double expected_output = 1;

    EXPECT_NEAR(Sigmoid(input), expected_output, 1e-9) << "Sigmoid function failed for positive input.";
}

TEST(ReLUTest, PositiveInput) {
    double input = 5.0;
    double expected_output = 5.0;
    
    EXPECT_EQ(ReLU(input), expected_output) << "ReLU function failed for positive input.";
}

TEST(ReLUTest, NegativeInput) {
    double input = -3.0;
    double expected_output = 0.0;
    EXPECT_DOUBLE_EQ(ReLU(input), expected_output);

    EXPECT_EQ(ReLU(input), expected_output) << "ReLU function failed for negative input.";
}

TEST(TanhTest, ZeroInput) {
    double input = 0.0;
    double expected_output = 0.0;
    
    EXPECT_DOUBLE_EQ(Tanh(input), expected_output) << "Tanh function failed for zero input.";
}

TEST(TanhTest, PositiveInput) {
    double input = 1.0;
    double expected_output = std::tanh(input);
    
    EXPECT_NEAR(Tanh(input), expected_output, 1e-7) << "Tanh function failed for positive input with tolerance.";
}

TEST(TanhTest, NegativeInput) {
    double input = -1.0;
    double expected_output = std::tanh(input);
    
    EXPECT_NEAR(Tanh(input), expected_output, 1e-7) << "Tanh function failed for positive input with tolerance.";
}

