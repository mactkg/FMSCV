//
//  2_slider.cpp
//  004
//
//  Created by Kenta Hara on 2015/10/21.
//  Copyright © 2015年 Kenta Hara. All rights reserved.
//

#include <opencv2/opencv.hpp>
int main() {
    cv::Mat imgIn = cv::imread("Lenna.jpg");
    cv::Mat imgGray;
    cv::Mat imgBinary;
    
    cv::namedWindow("result");
    int thresh = 128;
    cv::createTrackbar("thresh", "result", &thresh, 255);
    
    cv::cvtColor(imgIn, imgGray, CV_BGR2GRAY);
    while (1){
        cv::threshold(imgGray, imgBinary, thresh, 255, cv::THRESH_BINARY);
        cv::imshow("result", imgBinary);
        
        // ESC
        int key = cv::waitKey(30);
        if (key == 27)
            break;
    }
}
