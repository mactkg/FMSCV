//
//  4_segmentation.cpp
//  004
//
//  Created by Kenta Hara on 2015/10/21.
//  Copyright © 2015年 Kenta Hara. All rights reserved.
//

#include <opencv2/opencv.hpp>
int main() {
    cv::Mat imgIn = cv::imread("car.jpg");
    cv::Rect rect(156, 111, 293, 260);
    cv::Mat imgArea;
    cv::Mat imgMask;
    cv::Mat imgOut;
    cv::Mat bg_model, fg_model;
    
    cv::grabCut(imgIn, imgArea, rect, bg_model, fg_model, 1, cv::GC_INIT_WITH_RECT);
    cv::compare(imgArea, cv::GC_PR_FGD, imgMask, cv::CMP_EQ);
    
    imgIn.copyTo(imgOut, imgMask);
    
    cv::imshow("input", imgIn);
    cv::imshow("output", imgOut);
    cv::waitKey();
}