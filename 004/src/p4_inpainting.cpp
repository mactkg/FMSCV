//
//  p4_inpainting.cpp
//  004
//
//  Created by Kenta Hara on 2015/10/21.
//  Copyright © 2015年 Kenta Hara. All rights reserved.
//

#include <opencv2/opencv.hpp>

bool isPressed = false;
bool isDrawn = true;
int mouseX = -100;
int mouseY = -100;
int r = 5;

void mouseEvent(int event, int x, int y, int flags, void* param) {
    switch (event) {
        case cv::EVENT_LBUTTONDOWN:
            isPressed = true;
            break;
        case cv::EVENT_LBUTTONUP:
            isPressed = false;
            isDrawn = false;
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
    cv::Mat imgIn = cv::imread("lenna_inpaint.png");
    cv::Mat imgMask = cv::Mat::zeros(imgIn.rows, imgIn.cols, CV_8UC1);
    
    cv::namedWindow("window");
    cv::setMouseCallback("window", &mouseEvent);
    
    while (true) {
        cv::Mat imgOut = imgIn.clone();
        cv::circle(imgOut, cv::Point(mouseX, mouseY), r, cv::Scalar(0, 255, 0), CV_FILLED);
        
        if (isPressed) {
            cv::circle(imgMask, cv::Point(mouseX, mouseY), r, cv::Scalar(255), CV_FILLED);
            cv::add(imgIn, cv::Scalar(0, 255, 0), imgOut, imgMask);
        } else if (!isDrawn) {
            cv::inpaint(imgIn, imgMask, imgOut, 3, cv::INPAINT_NS);
            imgMask = cv::Mat::zeros(imgIn.rows, imgIn.cols, CV_8UC1);
            imgIn = imgOut.clone();
            isDrawn = true;
        }

        cv::imshow("window", imgOut);
        
        // ESC
        int key = cv::waitKey(20);
        std::cout << key << std::endl;
        if (key == 27) {
            break;
        } else if (key == 63232) { // UP
            r += 2;
        } else if (key == 63233) { // DOWN
            r -= 2;
        }
    }
}