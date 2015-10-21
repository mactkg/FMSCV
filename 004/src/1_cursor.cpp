//
//  main.cpp
//  template 
//
//  Created by Kenta Hara on 2015/10/14.
//  Copyright © 2015年 Kenta Hara. All rights reserved.
//

#include <opencv2/opencv.hpp>

cv::Scalar color(0, 255, 0);
int mouseX = -100;
int mouseY = -100;

void mouseEvent(int event, int x, int y, int flags, void* param) {
    switch (event) {
        case cv::EVENT_LBUTTONDOWN:
            color = cv::Scalar(0, 0, 255);
            break;
        case cv::EVENT_LBUTTONUP:
            color = cv::Scalar(0, 255, 0);
            break;
        case cv::EVENT_MOUSEMOVE:
            mouseX = x;
            mouseY = y;
            break;
        default:
            break;
    }
}

int main() {
    cv::Mat image = cv::imread("Lenna.jpg");
    cv::namedWindow("input");
    cv::setMouseCallback("input", &mouseEvent);
    
    while (true) {
        // draw a pointer
        cv::circle(image, cv::Point(mouseX, mouseY), 5, color, CV_FILLED);
        cv::imshow("input", image);
       
        // ESC
        int key = cv::waitKey(30);
        if (key == 27)
            break;
    }
}
