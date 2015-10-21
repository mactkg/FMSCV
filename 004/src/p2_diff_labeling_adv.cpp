//
//  p2_diff_labeling_adv.cpp
//  004
//
//  Created by Kenta Hara on 2015/10/21.
//  Copyright © 2015年 Kenta Hara. All rights reserved.
//

#include <opencv2/opencv.hpp>
int main() {
    cv::VideoCapture capture(0);
    
    cv::Mat background;
    cv::Mat smallBackground;
    cv::Mat target;
    cv::Mat smallTarget;
    cv::Mat backgroundGray;
    cv::Mat targetGray;
    cv::Mat diff;
    cv::Mat mask;
    cv::Mat label;
    cv::Mat result;
    
    // wait 1sec
    cv::waitKey(1000);
    
    // UI
    cv::namedWindow("camera");
    cv::namedWindow("mask");
    cv::namedWindow("result");
    int thresh = 128;
    cv::createTrackbar("thresh", "result", &thresh, 255);
    
    capture >> background;
    cv::resize(background, smallBackground, cv::Size(), 0.5, 0.5);
    cv::cvtColor(smallBackground, backgroundGray, CV_BGR2GRAY);
    
    
    while (1){
        capture >> target;
        cv::resize(target, smallTarget, cv::Size(), 0.5, 0.5);
        cv::cvtColor(smallTarget, targetGray, CV_BGR2GRAY);
        cv::absdiff(backgroundGray, targetGray, diff);
        
        result = target.clone();
        cv::threshold(diff, mask, thresh, 255, cv::THRESH_BINARY);
        smallTarget.copyTo(result, mask);
        
        int n = cv::connectedComponents(mask, label);
        for (int l = 1; l < MIN(n, 100); l++) {
            cv::Mat areaMask;
            cv::compare(label, l, areaMask, CV_CMP_EQ);
            cv::rectangle(result, cv::boundingRect(areaMask), cv::Scalar(0, 0, 255), 3);
        }
        
        cv::imshow("camera", smallTarget);
        cv::imshow("mask", mask);
        cv::imshow("result", result);
        
        // ESC
        int key = cv::waitKey(30);
        if (key == 27)
            break;
    }
}
