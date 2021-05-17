#include "GraphicalAlgorithmsLibrary.h"
#include "UILibrary.h"
#include "..\include\Utils.h"


int main()
{
	std::cout << "Testing that the DLL's work in the main project" << std::endl << std::endl;
	GraphLibraryTest();
	UILibraryTest();
	std::cout << std::endl << " ----------------------------------" << std::endl << std::endl;;

	/*std::cout << "Testing that the preprocessor macro that we defined is working" << std::endl << std::endl;
	std::string imPath = _SOLUTIONDIR;
	std::string imName = "\lena.jpg";
	imPath = imPath + imName;
	std::cout << "Solution Directory = " << imPath << std::endl;
	std::cout << std::endl << " ----------------------------------" << std::endl << std::endl;;*/

	/*std::cout << "Reading and opening an image from disk" << std::endl << std::endl;
	cv::Mat image;
	image = cv::imread(imPath);
	cv::imshow(imPath, image);
	cv::waitKey(0);*/
	
	cv::Mat image;
	std::cout << "Testing that the function to read the image works - Test if path is OK" << std::endl << std::endl;
	std::string imPath = "C:\\Users\\Laur\\source\\repos\\Practica Siemens\\Application\\Test_Data\\lena.jpg";
	image = Utils::ReadImage(imPath);
	std::cout << std::endl << " ----------------------------------" << std::endl;

	std::cout << "Testing that the function to read the image works - Test if path is wrong" << std::endl << std::endl;
	std::string wrongPath = "C:\\Users\\Laur\\source\\repos\\Practica Siemens\\Application\\Test_Data\\la.jpg";
	image = Utils::ReadImage(wrongPath);
	if (image.empty())
		std::cout << "ERROR" << std::endl;

	return 0;
}