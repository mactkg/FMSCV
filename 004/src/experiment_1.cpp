//
//  experiment_1.cpp
//  004
//
//  Created by Kenta Hara on 2015/10/22.
//  Copyright © 2015年 Kenta Hara. All rights reserved.
//

#include <opencv2/opencv.hpp>
int main() {
    cv::VideoCapture capture(0);
    
    cv::Mat prevOriginal;
    cv::Mat prev;
    cv::Mat currentOriginal;
    cv::Mat current;
    cv::Mat grayPrev;
    cv::Mat grayCurrent;
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
   
    // first grayscale frame
    capture >> prevOriginal;
    cv::resize(prevOriginal, prev, cv::Size(), 0.5, 0.5);
    cv::cvtColor(prev, grayPrev, CV_BGR2GRAY);
    
    mask = cv::Mat::zeros(prev.rows, prev.cols, CV_8UC1);
    
    while (1){
        // second grayscale frame
        capture >> currentOriginal;
        cv::resize(currentOriginal, current, cv::Size(), 0.5, 0.5);
        cv::cvtColor(current, grayCurrent, CV_BGR2GRAY);
        
        // get a diff
        cv::absdiff(grayPrev, grayCurrent, diff);
       
        // inpaint
        cv::Mat tmpMask;
        result.release();
        cv::threshold(diff, tmpMask, thresh, 255, cv::THRESH_BINARY);
        mask *= 0.3;
        mask = mask + tmpMask;
        cv::inpaint(current, mask, result, 3, cv::INPAINT_NS);
      
        // ready for next frame
        cv::cvtColor(result, grayPrev, CV_BGR2GRAY);
        
        cv::imshow("camera", current);
        cv::imshow("mask", mask);
        cv::imshow("result", result);
        
        // ESC
        int key = cv::waitKey(30);
        if (key == 27)
            break;
    }
}