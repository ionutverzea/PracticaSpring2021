#include "..\include\Utils.h"
#include <iostream>

cv::Mat Utils::ReadImage(std::string imagePath, bool showImage)
{
	cv::Mat image;
	image = cv::imread(imagePath);

	if (image.empty())
	{
		std::cout << "Could not read the image: " << imagePath << std::endl;
		image.setTo(0);
		return image;
	}
	else
		if (!showImage)
		{
			return image;
		}
		else
		{
			cv::imshow(imagePath, image);
			cv::waitKey(0);
			return image;
		}
}
