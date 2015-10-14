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
    
    // AKAZE
    cv::waitKey(1000);
    cv::Mat original, img; capture >> original;// = cv::imread("Scene.jpg");
    cv::resize(original, img, cv::Size(), 0.5, 0.5);
    
    cv::Ptr<cv::AKAZE> detector = cv::AKAZE::create();
    cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create("BruteForce");
    
    std::vector<cv::KeyPoint> keypointsOriginal;
    detector->detect(img, keypointsOriginal);
    cv::Mat descriptorOriginal;
    detector->compute(img, keypointsOriginal, descriptorOriginal);
    
    
    
    while (true) {
        capture >> image;
        cv::resize(image, smallImage, cv::Size(), 0.5, 0.5);
       
        std::vector<cv::KeyPoint> keypoints;
        detector->detect(smallImage, keypoints);
        cv::Mat descriptor;
        detector->compute(smallImage, keypoints, descriptor);
       
        std::vector<cv::DMatch> matches;
        matcher->match(descriptorOriginal, descriptor, matches);
        
        cv::Mat imgResult;
        cv::drawMatches(img, keypointsOriginal, smallImage, keypoints, matches, imgResult);
        
        int key = cv::waitKey(3);
        if (key == 'q') {
            break;
        }
        
        cv::imshow("video", imgResult);
    }
    
    return 0;
}
