#include "conv2D.hpp"

int main() {
    Matrix input(6, 6);
    input << 3, 1, 0, 2, 5, 6,
             4, 2, 1, 1, 4, 7,
             5, 4, 0, 0, 1, 2,
             1, 2, 2, 1, 3, 4,
             6, 3, 1, 0, 5, 2,
             3, 1, 0, 1, 3, 3;

    Matrix kernel(3, 3);
    kernel <<  -1, 0, 1,
               -1, 0, 1,
               -1, 0, 1;

    Matrix output = conv2D(input, kernel);

    cout << "Output of convolution:" << endl;
    cout << output << endl;

    Matrix outputPadded = conv2D_Padded(input, kernel, 1);
    cout << "Output of convolution with padding:" << endl;
    cout << outputPadded << endl;

    Matrix outputOptimized = conv2D_Optimizer(input, kernel, 1);
    cout << "Output of optimized convolution:" << endl;
    cout << outputOptimized << endl;

    return 0;
}