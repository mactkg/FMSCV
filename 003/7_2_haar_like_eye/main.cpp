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
    
    cv::CascadeClassifier cascade;
    cascade.load("haarcascade_eye.xml");
    
    std::vector<cv::Rect> faces;
    cascade.detectMultiScale(image, faces);
    
    for (std::vector<cv::Rect>::iterator it = faces.begin(); it != faces.end(); it++) {
        cv::rectangle(image, *it, cv::Scalar(0, 0, 255));
    }
    
    cv::imshow("result", image);
    cv::waitKey();
    
    return 0;
}
