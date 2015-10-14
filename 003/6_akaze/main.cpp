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
    cv::Mat img = cv::imread("Lenna.jpg");
    cv::Mat imgMod = cv::imread("scene.jpg");
    
    cv::Ptr<cv::AKAZE> detector = cv::AKAZE::create();
    cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create("BruteForce");
    
    
    std::vector<cv::KeyPoint> keypointsOriginal;
    detector->detect(img, keypointsOriginal);

    std::vector<cv::KeyPoint> keypointsMod;
    detector->detect(imgMod, keypointsMod);
  
    
    cv::Mat descriptorOriginal;
    detector->compute(img, keypointsOriginal, descriptorOriginal);

    cv::Mat descriptorMod;
    detector->compute(imgMod, keypointsMod, descriptorMod);
  
    
    std::vector<cv::DMatch> matches;
    matcher->match(descriptorOriginal, descriptorMod, matches);
   
    
    cv::Mat imgResult;
    cv::drawMatches(img, keypointsOriginal, imgMod, keypointsMod, matches, imgResult);
    cv::namedWindow("output");
    cv::imshow("output", imgResult);
    cv::waitKey();
    
    return 0;
}
