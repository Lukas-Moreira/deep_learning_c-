#include "../headers/activation_functions.hpp"

/**
 * @brief ReLU activation function
 * 
 * ReLU is :
 *      x if x > 0
 *      0 otherwise
 * 
 * @param x value to apply ReLU on
 * @return float 
 */
float ReLU(float x) {
    return (x > 0.f) ? x : 0.f;
}

/**
 * @brief Sigmoid activation function
 * 
 * Sigmoid is defined as :
 *     1 / (1 + exp(-x))
 * 
 * @param x value to apply Sigmoid on
 * @return float 
 */
float Sigmoid(float x) {
    return 1.f / (1.f + exp(-x));
}

/**
 * @brief Tanh activation function
 * 
 * Tanh is defined as :
 *     (exp(x) - exp(-x)) / (exp(x) + exp(-x))
 * 
 * @param x 
 * @return float 
 */
float Tanh(float x){
    return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
}