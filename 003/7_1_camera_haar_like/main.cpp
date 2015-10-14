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
    cv::VideoCapture capture(0);
   
    if (!capture.isOpened()) {
        return 0;
    }
   
    cv::Mat image;
    cv::Mat smallImage;
    cv::namedWindow("video");
    
    while (true) {
        capture >> image;
        cv::resize(image, smallImage, cv::Size(), 0.5, 0.5);
        
        cv::CascadeClassifier cascade;
        cascade.load("haarcascade_frontalface_alt.xml");
        
        std::vector<cv::Rect> faces;
        cascade.detectMultiScale(smallImage, faces);
        
        for (std::vector<cv::Rect>::iterator it = faces.begin(); it != faces.end(); it++) {
            cv::rectangle(smallImage, *it, cv::Scalar(0, 0, 255));
        }
        
        int key = cv::waitKey(3);
        if (key == 'q') {
            break;
        }
        
        cv::imshow("video", smallImage);
    }
    
    return 0;
}
