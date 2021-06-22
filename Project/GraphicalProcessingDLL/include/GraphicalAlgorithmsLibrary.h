#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#ifdef G_LIB_as_DLL
#define GRAPHICALLIBRARY_API __declspec(dllexport)
#else
#define GRAPHICALLIBRARY_API __declspec(dllimport)
#endif

///\brief				Function that applies a sepia effect on a given image
///\param [in]	image		cv::Mat object containing the image that the user wants to modify
///\return			cv::Mat object containing the image with the sepia efect applied on it
extern "C" GRAPHICALLIBRARY_API cv::Mat SepiaFilter(cv::Mat const& image);

///\brief				Function that applies a blur effect on a given image
///\param [in]	image		cv::Mat object containing the image that the user wants to modify
///\param [in]	kernel_size		integer that represents the size of the blur kernel
///\return			cv::Mat object containing the image with the blur efect applied on it
extern "C" GRAPHICALLIBRARY_API cv::Mat BlurFilter(cv::Mat const& image, const int kernel_size);

///\brief				Function that applies a grayscale effect (with the average method) on a given image
///\param [in]	image		cv::Mat object containing the image that the user wants to modify
///\return			cv::Mat object containing the image with the grayscale efect applied on it
extern "C" GRAPHICALLIBRARY_API cv::Mat GrayScale_Average(cv::Mat const& image);

///\brief				Function that applies a grayscale effect (with the luminance method) on a given image
///\param [in]	image		cv::Mat object containing the image that the user wants to modify
///\return			cv::Mat object containing the image with the grayscale efect applied on it
extern "C" GRAPHICALLIBRARY_API cv::Mat GrayScale_Luminance(cv::Mat const& image);

///\brief				Helper function for Two_Tones() function
///\param [in]	channel		cv::Mat object representing a channel of the image
///\param [in]	exp				float number representing the exponent
///\return			cv::Mat object containing the channel after being modified with the exponent
extern "C" GRAPHICALLIBRARY_API cv::Mat ExponentialFunction(cv::Mat channel, float exp);

///\brief				Function that applies a two tones effect on a given image
///\param [in]	image		cv::Mat object containing the image that the user wants to modify
///\return			cv::Mat object containing the image with the two tones efect applied on it
extern "C" GRAPHICALLIBRARY_API cv::Mat Two_Tones(cv::Mat image);

///\brief				Function that applies a negative effect on a given image
///\param [in]	image		cv::Mat object containing the image that the user wants to modify
///\return			cv::Mat object containing the image with the negative efect applied on it
extern "C" GRAPHICALLIBRARY_API cv::Mat Negative(cv::Mat const& image);

///\brief				Helper function for Emboss() function
///\param [in]	size		integer representing the size of the kernel
///\return			cv::Mat object containing the modified kernel
extern "C" GRAPHICALLIBRARY_API cv::Mat KernelGenerator(int size);

///\brief				Function that applies an emboss effect on a given image
///\param [in]	image		cv::Mat object containing the image that the user wants to modify
///\return			cv::Mat object containing the image with the emboss efect applied on it
extern "C" GRAPHICALLIBRARY_API cv::Mat Emboss(cv::Mat image);

///\brief				Helper function needed for the cv::CreateTrackbar() function
inline static void nothing(int x, void* data) {};

///\brief				Function that changes the brightness of a given image
///\param [in]	image		cv::Mat object containing the image that the user wants to modify
///\param [in]	scale		integer representing the number depending on which the pixels will be modified
///\return				cv::Mat object containing the image with the changed brightness
extern "C" GRAPHICALLIBRARY_API cv::Mat Brightness(cv::Mat image, int scale);

extern "C" GRAPHICALLIBRARY_API cv::Mat TV_60(cv::Mat image);



