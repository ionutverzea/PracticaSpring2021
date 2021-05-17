#pragma once
#include <opencv2/opencv.hpp>

class Utils
{
public:
	static cv::Mat ReadImage(std::string imagePath, bool showImage = false);
};