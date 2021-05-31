#include "GraphicalAlgorithmsLibrary.h"
#include "UILibrary.h"
#include "..\include\Utils.h"


int main()
{
	cv::Mat image;
	cv::Mat processedImage;
	std::string imPath = "C:\\Users\\Laur\\source\\repos\\Practica Siemens\\Application\\Test_Data\\lena.jpg";

	image = Utils::ReadImage(imPath);
	//Utils::ShowImage(image);

	//processedImage = SepiaFilter(image);
	//processedImage = BlurFilter(image, 7);
	//processedImage = GrayScale_Average(image);
	//processedImage = GrayScale_Luminance(image);
	//processedImage = Negative(image);
	processedImage = Two_Tones(image);
	//processedImage = Emboss(image);
	Utils::ShowImage(processedImage);

	return 0;
}