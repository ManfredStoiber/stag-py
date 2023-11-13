#include "Stag.h"
#include "opencv2/opencv.hpp"
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include "StagWrapper.cpp"

int main() {
  cv::Mat image = cv::imread("../00003.png", cv::ImreadModes::IMREAD_GRAYSCALE);
  cv::imshow("img", image);
  //Stag stag(15, 7, true);
  //stag.detectMarkers(image);
  detectMarkers(image);
  //stag.logResults("");
  cv::waitKey(0);
  return 0;
}