#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <QtCore/qstring.h>


class Utils
{
public:

	///\brief				Reads an image from the disk given the path to the respective image
	///\param [in]	imagePath		string containing the path to the image that we want to read
	///\return			Returns cv::Mat object containing the image if the path was correct, else an empty cv::Mat object
	static cv::Mat ReadImage(std::string imagePath);

	///\brief				Function to display the image on screen
	///\param [in]	image		cv::Mat object containing the image to be shown
	static void ShowImage(cv::Mat image);

	static std::vector<QString> ReadFile(const std::string& filepath);

	static void WriteFile(const std::string& filepath, std::vector<QString> files);
};