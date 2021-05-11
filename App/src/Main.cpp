#include "GraphicalAlgorithmsLibrary.h"
#include "UILibrary.h"
#include <opencv2/opencv.hpp>

int main()
{
	std::cout << "Testing that the DLL's work in the main project" << std::endl << std::endl;
	GraphLibraryTest();
	UILibraryTest();
	std::cout << std::endl << " ----------------------------------" << std::endl << std::endl;;

	std::cout << "Testing that the preprocessor macro that we defined is working" << std::endl << std::endl;
	std::string imPath = _SOLUTIONDIR;
	std::string imName = "\lena.jpg";
	imPath = imPath + imName;
	std::cout << "Solution Directory = " << imPath << std::endl;
	std::cout << std::endl << " ----------------------------------" << std::endl << std::endl;;

	std::cout << "Reading and opening an image from disk" << std::endl << std::endl;
	cv::Mat image;
	image = cv::imread(imPath);
	cv::imshow(imPath, image);
	cv::waitKey(0);

	return 0;
}