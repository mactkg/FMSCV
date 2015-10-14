//
//  main.cpp
//  003
//
//  Created by Kenta Hara on 2015/10/14.
//  Copyright © 2015年 Kenta Hara. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, const char * argv[]) {
    cv::Mat imgIn = cv::imread("Lenna.jpg");
    cv::Mat imgOut;
    
    cv::cvtColor(imgIn, imgOut, CV_BGR2GRAY);
    
    cv::namedWindow("input");
    cv::namedWindow("output");
    
    cv::imshow("input", imgIn);
    cv::imshow("output", imgOut);
    cv::waitKey();
    
    return 0;
}
