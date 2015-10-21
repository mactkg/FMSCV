//
//  3_labeling.cpp
//  004
//
//  Created by Kenta Hara on 2015/10/21.
//  Copyright © 2015年 Kenta Hara. All rights reserved.
//

#include <opencv2/opencv.hpp>
int main() {
    
    cv::Mat imgIn = cv::imread("objects.png", cv::IMREAD_GRAYSCALE);
    cv::Mat imgBin;
    cv::Mat imgLabel;
    
    cv::threshold(imgIn, imgBin, 0, 255, cv::THRESH_BINARY);
    
    int n = cv::connectedComponents(imgBin, imgLabel, 8);
    
    for (int label = 0; label<n; label++) {
        cv::Mat imgAreaMask;
        
        cv::compare(imgLabel, label, imgAreaMask, CV_CMP_EQ);
        
        cv::imshow("mask", imgAreaMask);
        cv::waitKey();
    }
}