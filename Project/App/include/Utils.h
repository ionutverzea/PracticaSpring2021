#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <QtCore/qstring.h>


class Utils
{
public:

	///\brief				Reads an image from the disk given the path to the respective image.
	///\param [in]	imagePath		string containing the path to the image that we want to read.
	///\return			Returns cv::Mat object containing the image if the path was correct, else an empty cv::Mat object.
	static cv::Mat ReadImage(std::string imagePath);

	///\brief				Function to display the image on screen.
	///\param [in]	image		cv::Mat object containing the image to be shown.
	static void ShowImage(cv::Mat image);

	///\brief				Function that read the content of a file given the file's path.
	///\param [in]	filepath	string object containing the path to the file.
	///\return			Returns a vector of QString objects containing all the paths read from the input file. 
	static std::vector<QString> ReadFile(const std::string& filepath);

	///\brief				Function that write elements from a vector into a file.
	///\param [in]	filepath	string containing the path to the file.
	///\param [in]	files			vector of QString objects containing the strings to be written in the file.
	static void WriteFile(const std::string& filepath, std::vector<QString> files);
};