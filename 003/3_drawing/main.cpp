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
    cv::Mat image = cv::imread("Lenna.jpg");
    cv::namedWindow("input");
  
    // 画素データはBGRで並んでるので色を示してるcv::ScalarにはBGRの順で送らないといけない
    cv::line(image, cv::Point(100, 100), cv::Point(200, 200), cv::Scalar(0, 255, 255), 3, CV_AA);
    cv::rectangle(image, cv::Point(10, 10), cv::Point(150, 80), cv::Scalar(0, 255, 0), 2, CV_AA);
    cv::circle(image, cv::Point(image.cols/2, image.rows/2), 100, cv::Scalar(255, 255, 0), 2, CV_AA);
    cv::putText (image, "OpenCV", cv::Point(20, 50), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(255, 0, 0), 2, CV_AA);
    
    cv::imshow("input", image);
    cv::waitKey();
    
    return 0;
}