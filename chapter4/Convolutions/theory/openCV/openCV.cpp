#include "include/conv2D.hpp"

int main() {    
    Matrix G_x(3,3), G_y(3,3);
    G_x << 1, 0, -1,
           2, 0, -2,
           1, 0, -1;

    G_y << 1,  2,  1,
           0,  0,  0,
          -1, -2, -1;

    Mat src = imread("../chess.jpg", IMREAD_COLOR);
    Mat img_gray;
    cvtColor(src, img_gray, COLOR_BGR2GRAY);

    Matrix X;
    cv2eigen(img_gray, X);

    const int padding = (G_x.rows() - 1) / 2; // Assuming G_x and G_y have the same size

    auto G_x_conv = conv2D_Padded(X, G_x, padding);
    auto G_y_conv = conv2D_Padded(X, G_y, padding);
    Matrix Combined = G_x_conv + G_y_conv;

    Mat temp, G_x_result, G_y_result, Combined_result;
    eigen2cv(G_x_conv, temp);
    temp.convertTo(G_x_result, CV_8UC1);
    eigen2cv(G_y_conv, temp);
    temp.convertTo(G_y_result, CV_8UC1);
    eigen2cv(Combined, temp);
    temp.convertTo(Combined_result, CV_8UC1);

    imshow("Original Image", src);
    imshow("G_x Convolution Result", G_x_result);
    imshow("G_y Convolution Result", G_y_result);
    imshow("Combined Gradient Magnitude", Combined_result);
    waitKey(0);
}