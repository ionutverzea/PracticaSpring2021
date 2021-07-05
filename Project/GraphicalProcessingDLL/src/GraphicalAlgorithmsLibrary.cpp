#include "GraphicalAlgorithmsLibrary.h"
#include <iostream>

GRAPHICALLIBRARY_API cv::Mat SepiaFilter(cv::Mat const& image)
{
	cv::Mat transformedImage;
	cv::Mat kernel = (cv::Mat_<float>(3, 3) << 0.272, 0.534, 0.131,
		0.345, 0.686, 0.168,
		0.393, 0.769, 0.189); //https://stackoverflow.com/questions/15869198/opencv-help-me-with-sepia-kernel
	cv::transform(image, transformedImage, kernel);
	return transformedImage;
}

GRAPHICALLIBRARY_API cv::Mat BlurFilter(cv::Mat const& image, const int kernel_size)
{
	cv::Mat transformedImage;
	cv::Point anchor = cv::Point(-1, -1); // punctul central
	double delta = 0;
	int ddepth = -1;
	cv::Mat kernel = cv::Mat::ones(kernel_size, kernel_size, CV_32F) / (float)(kernel_size * kernel_size);

	cv::filter2D(image, transformedImage, ddepth, kernel, anchor, delta, cv::BORDER_DEFAULT);
	return transformedImage;
}

GRAPHICALLIBRARY_API cv::Mat GrayScale_Average(cv::Mat const& image)
{
	cv::Mat imageMat = image;
	cv::Mat grayMat = cv::Mat(imageMat.rows, imageMat.cols, CV_8UC1);

	for (int row = 0; row < image.rows; ++row)
	{
		uchar* imageMatRow = imageMat.ptr<uchar>(row);
		uchar* grayMatRow = grayMat.ptr<uchar>(row);

		for (int col = 0; col < image.cols; ++col)
		{
			int sum = 0;
			int pixel = col * imageMat.channels();
			for (int i = 0; i < imageMat.channels(); ++i)
			{
				sum += imageMatRow[pixel + i];
			}
			grayMatRow[col] = round(sum / imageMat.channels());
		}
	}
	return grayMat;
}

GRAPHICALLIBRARY_API cv::Mat GrayScale_Luminance(cv::Mat const& image)
{
	cv::Mat imageMat = image;
	cv::Mat grayMat = cv::Mat(imageMat.rows, imageMat.cols, CV_8UC1);

	for (int row = 0; row < image.rows; ++row)
	{
		uchar* imageMatRow = imageMat.ptr<uchar>(row);
		uchar* grayMatRow = grayMat.ptr<uchar>(row);

		for (int col = 0; col < image.cols; ++col)
		{
			int pixel = col * image.channels();

			float red = imageMatRow[pixel] * 0.3;
			float green = imageMatRow[pixel + 1] * 0.59;
			float blue = imageMatRow[pixel + 2] * 0.11;

			grayMatRow[col] = red + green + blue;
		}
	}
	return grayMat;
}

GRAPHICALLIBRARY_API cv::Mat ExponentialFunction(cv::Mat channel, float exp)
{
	cv::Mat table(1, 256, CV_8U);
	for (int i = 0; i < 256; i++)
		table.at<uchar>(i) = std::min((int)std::pow(i, exp), 255);
	cv::LUT(channel, table, channel);
	return channel;
}

GRAPHICALLIBRARY_API cv::Mat Two_Tones(cv::Mat image)
{
	cv::namedWindow("image");
	int slider1 = 0;
	int slider2 = 1;
	int slider3 = 3;
	int slider4 = 0;
	std::string switch1 = "0 : BLUE n1 : GREEN n2 : RED";
	std::string switch2 = "0 : BLUE n1 : GREEN n2 : RED n3 : NONE";
	std::string switch3 = "0 : DARK n1 : LIGHT";
	cv::createTrackbar("exponent", "image", &slider1, 10, nothing);
	cv::createTrackbar(switch1, "image", &slider2, 2, nothing);
	cv::createTrackbar(switch2, "image", &slider3, 3, nothing);
	cv::createTrackbar(switch3, "image", &slider4, 1, nothing);

	while (true)
	{
		int exp1 = cv::getTrackbarPos("exponent", "image");
		float exp = 1 + exp1 / 100.0;
		int s1 = cv::getTrackbarPos(switch1, "image");
		int s2 = cv::getTrackbarPos(switch2, "image");
		int s3 = cv::getTrackbarPos(switch3, "image");
		cv::Mat result = image.clone();
		cv::Mat channels[3];
		cv::split(image, channels);
		for (int i = 0; i < 3; i++) {
			if ((i == s1) || (i == s2)) {
				channels[i] = ExponentialFunction(channels[i], exp);
			}
			else {
				if (s3) {
					channels[i] = ExponentialFunction(channels[i], 2 - exp);
				}
				else {
					channels[i] = cv::Mat::zeros(channels[i].size(), CV_8UC1);
				}
			}
		}
		std::vector<cv::Mat> newChannels{ channels[0],channels[1],channels[2] };
		cv::merge(newChannels, result);
		cv::imshow("image", result);
		if (cv::waitKey(1) == 'q')
			return result;
	}
	cv::destroyAllWindows();
}

GRAPHICALLIBRARY_API cv::Mat Negative(cv::Mat const& image)
{
	return 255 - image;
}

GRAPHICALLIBRARY_API cv::Mat KernelGenerator(int size)
{
	cv::Mat kernel = cv::Mat(size, size, CV_8S, cv::Scalar(0));
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (i < j)
				kernel.at<schar>(i, j) = -1;
			else if (i > j)
				kernel.at<schar>(i, j) = 1;
		}
	return kernel;
}

GRAPHICALLIBRARY_API cv::Mat Emboss(cv::Mat image)
{
	cv::namedWindow("image");
	int slider = 0;
	int slider2 = 0;
	cv::createTrackbar("size", "image", &slider, 8, nothing);
	cv::createTrackbar("0 : BL n1 : BR n2 : TR n3 : BR", "image", &slider2, 3, nothing);
	while (true)
	{
		int size = cv::getTrackbarPos("size", "image");
		size += 2;
		int s = cv::getTrackbarPos("0 : BL n1 : BR n2 : TR n3 : BR", "image");
		int height = image.size().height;
		int width = image.size().width;

		cv::Mat y = cv::Mat(height, width, CV_8U, cv::Scalar(128));
		cv::Mat gray;
		cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
		cv::Mat kernel = KernelGenerator(size);
		for (int i = 0; i < s; i++)
			cv::rotate(kernel, kernel, cv::ROTATE_90_COUNTERCLOCKWISE);
		cv::Mat dest;
		cv::filter2D(gray, dest, -1, kernel);
		cv::Mat result;
		cv::add(dest, y, result);
		cv::imshow("image", result);
		if (cv::waitKey(1) == 'q')
			return result;
	}
	cv::destroyAllWindows();
}

GRAPHICALLIBRARY_API cv::Mat Brightness(cv::Mat image, int scale) {
	cv::Mat result;

	image.convertTo(result, -1, 1, scale);

	return result;
}

GRAPHICALLIBRARY_API cv::Mat TV_60(cv::Mat image)
{
	cv::namedWindow("image");
	int slider = 0;
	int slider2 = 0;
	cv::createTrackbar("val", "image", &slider, 255, nothing);
	cv::createTrackbar("treshold", "image", &slider2, 100, nothing);
	while (true)
	{
		int height = image.size().height;
		int width = image.size().width;
		cv::Mat gray;
		cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
		float tresh = cv::getTrackbarPos("treshold", "image");
		float val = cv::getTrackbarPos("val", "image");

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (rand() % 100 <= tresh) {
					if (rand() % 2 == 0)
						gray.at<uchar>(i, j) = std::min(gray.at<uchar>(i, j) + rand() % ((int)val + 1), 255);
					else
						gray.at<uchar>(i, j) = std::max(gray.at<uchar>(i, j) - rand() % ((int)val + 1), 0);
				}
			}
		}
		cv::imshow("image", gray);
		if (cv::waitKey(1) == 'q')
		{
			return gray;
		}
	}
	cv::destroyAllWindows();
}

