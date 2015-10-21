//
//  5_inpainting.cpp
//  004
//
//  Created by Kenta Hara on 2015/10/21.
//  Copyright © 2015年 Kenta Hara. All rights reserved.
//

#include <opencv2/opencv.hpp>

int main() {
    cv::Mat imgIn = cv::imread("lenna_inpaint.png");
    cv::Mat imgMask = cv::imread("inpaint_mask.png", cv::IMREAD_GRAYSCALE);
    
    cv::Mat imgOut_NS;
    cv::Mat imgOut_TELEA;
    cv::inpaint(imgIn, imgMask, imgOut_NS, 3, cv::INPAINT_NS);
    cv::inpaint(imgIn, imgMask, imgOut_TELEA, 3, cv::INPAINT_TELEA);
    
    cv::imshow("input", imgIn);
    cv::imshow("output(NS)", imgOut_NS);
    cv::imshow("output(TELEA)", imgOut_TELEA);
    cv::waitKey();
}