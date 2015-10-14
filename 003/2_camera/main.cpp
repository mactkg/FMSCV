//
//  main.cpp
//  2_camera
//
//  Created by Kenta Hara on 2015/10/14.
//  Copyright © 2015年 Kenta Hara. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, const char * argv[]) {
    cv::VideoCapture capture(0);
    
    if (!capture.isOpened()) {
        return 0;
    }
    
    cv::Mat image;
    cv::namedWindow("video");
    
    while (true) {
        capture >> image;
        cv::imshow("video", image);
        int key = cv::waitKey(30);
        if (key == 'q') {
            break;
        }
    }
    
    return 0;
}
