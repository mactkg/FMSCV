//
//  p2_diff_labeling.cpp
//  004
//
//  Created by Kenta Hara on 2015/10/21.
//  Copyright © 2015年 Kenta Hara. All rights reserved.
//

#include <opencv2/opencv.hpp>
int main() {
    cv::Mat background = cv::imread("background.jpg");
    cv::Mat target = cv::imread("object_and_background.jpg");
    cv::Mat backgroundGray;
    cv::Mat targetGray;
    cv::Mat diff;
    cv::Mat mask;
    cv::Mat label;
    cv::Mat result;
    
    cv::namedWindow("result");
    int thresh = 128;
    cv::createTrackbar("thresh", "result", &thresh, 255);
    
    cv::cvtColor(background, backgroundGray, CV_BGR2GRAY);
    cv::cvtColor(target, targetGray, CV_BGR2GRAY);
    cv::absdiff(backgroundGray, targetGray, diff);
    
    while (1){
        result = target.clone();
        
        cv::threshold(diff, mask, thresh, 255, cv::THRESH_BINARY);
        int n = cv::connectedComponents(mask, label);
        for (int l = 1; l < n; l++) {
            cv::Mat areaMask;
            cv::compare(label, l, areaMask, CV_CMP_EQ);
            cv::rectangle(result, cv::boundingRect(areaMask), cv::Scalar(0, 0, 255), 3);
        }
        
        cv::imshow("result", result);
        
        // ESC
        int key = cv::waitKey(30);
        if (key == 27)
            break;
    }
}
