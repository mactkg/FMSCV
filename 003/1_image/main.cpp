//
//  main.cpp
//  1_image 
//
//  Created by Kenta Hara on 2015/10/14.
//  Copyright © 2015年 Kenta Hara. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, const char * argv[]) {
    cv::Mat image = cv::imread("Lenna.jpg");
    cv::namedWindow("input");
    cv::imshow("input", image);
    cv::waitKey();
    cv::imwrite("output.jpg", image);
    
    return 0;
}
