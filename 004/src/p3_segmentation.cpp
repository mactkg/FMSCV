//
//  p3_segmentation.cpp
//  004
//
//  Created by Kenta Hara on 2015/10/21.
//  Copyright © 2015年 Kenta Hara. All rights reserved.
//

#include <opencv2/opencv.hpp>

bool isPressed = false;
bool isDrawn = false;
cv::Point2d begin(0, 0);
cv::Rect rect(0, 0, 100, 100);
int mouseX = -100;
int mouseY = -100;

void mouseEvent(int event, int x, int y, int flags, void* param) {
    switch (event) {
        case cv::EVENT_LBUTTONDOWN:
            begin.x = x;
            begin.y = y;
            isPressed = true;
            break;
        case cv::EVENT_LBUTTONUP:
            rect.x = MIN(begin.x, x);
            rect.width = MAX(cv::abs(x - begin.x), 10);
            rect.y = MIN(begin.y, y);
            rect.height = MAX(cv::abs(y - begin.y), 10);
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
    cv::Mat imgIn = cv::imread("car.jpg");
    cv::Mat imgArea;
    cv::Mat imgMask;
    cv::Mat imgOut;
    cv::Mat result;
    cv::Mat bg_model, fg_model;
  
    cv::namedWindow("input");
    cv::namedWindow("result");
    cv::setMouseCallback("output", &mouseEvent);

    while (true) {
        if (isPressed || !isDrawn) {
            imgOut = imgIn.clone();
        }
        
        if (isPressed) {
            cv::rectangle(imgOut, begin, cv::Point(mouseX, mouseY), cv::Scalar(0, 0, 255), 3);
        } else if(!isDrawn) {
            cv::rectangle(imgOut, rect, cv::Scalar(0, 0, 255), 3);
            cv::grabCut(imgIn, imgArea, rect, bg_model, fg_model, 1, cv::GC_INIT_WITH_RECT);
            cv::compare(imgArea, cv::GC_PR_FGD, imgMask, cv::CMP_EQ);
            
            result.release();
            imgIn.copyTo(result, imgMask);

            isDrawn = true;
        }
        
        cv::imshow("input", imgOut);
        cv::imshow("result", result);
        
        // ESC
        int key = cv::waitKey(20);
        if (key == 27) {
            break;
        }
    }
}