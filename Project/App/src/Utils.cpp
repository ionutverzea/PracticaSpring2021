#include "..\include\Utils.h"
#include <iostream>
#include <fstream>

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

std::vector<QString> Utils::ReadFile(const std::string& filepath)
{
	std::vector<QString> temp;
	std::ifstream myfile("recentFiles.txt");
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			std::string line;
			std::getline(myfile, line);
			QString qline = QString::fromStdString(line);
			temp.push_back(qline);
		}
	}
	else
	{
		std::cout << "Unable to open file.";
	}
	myfile.close();
	return temp;
}

void Utils::WriteFile(const std::string& filepath, std::vector<QString> files)
{
	std::ofstream myfile("recentFiles.txt");
	if (myfile.is_open())
	{
		for each (QString var in files)
		{
			myfile << var.toStdString() << std::endl;
		}
		myfile.close();
	}
	else
	{
		std::cout << "Unable to open file.";
	}
}
