#include "..\include\Utils.h"
#include <iostream>

cv::Mat Utils::ReadImage(std::string imagePath)
{
	cv::Mat image;
	image = cv::imread(imagePath);

	if (image.empty())
	{
		std::cout << "Could not read the image: " << imagePath << std::endl;
		image.setTo(0);
		return image;
	}
	return image;
}

void Utils::ShowImage(cv::Mat image)
{
	if (image.empty())
	{
		std::cout << "Image is not loaded properly" << std::endl;
		return;
	}

	cv::imshow("Image", image);
	cv::waitKey(0);
}
