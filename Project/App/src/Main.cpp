#include "GraphicalAlgorithmsLibrary.h"
#include "UILibrary.h"
#include "..\include\Utils.h"


int main()
{
	cv::Mat image;
	cv::Mat processedImage;
	std::string imPath = "D:\\PB_SIEMENS\\Procesare_img\\Test_Data\\lena.jpg";

	image = Utils::ReadImage(imPath);
	//Utils::ShowImage(image);

	//processedImage = SepiaFilter(image);
	//processedImage = BlurFilter(image, 7);
	//processedImage = GrayScale_Average(image);
	//processedImage = GrayScale_Luminance(image);
	//processedImage = Negative(image);
	//processedImage = Two_Tones(image);
	//processedImage = Emboss(image);
	//processedImage = Brightness(image, 100);
	processedImage = TV_60(image);
	
	Utils::ShowImage(processedImage);
	
	return 0;
}