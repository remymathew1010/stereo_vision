#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>

#include "CalibrationIO.h"

int main(int argc, char *argv[]) {

	std::string calibrationFile = "../calibration.txt"; // This will depend on where you saved it
	std::string image1File = "../bell_left.jpg";
	std::string image2File = "../bell_right.jpg";

	cv::Mat K1, K2, R, T;
	std::vector<double> d1, d2;
	readStereoCalibration(calibrationFile, K1, d1, K2, d2, R, T);

	std::cout << "K1" << std::endl << K1 << std::endl;
	std::cout << "K2" << std::endl << K2 << std::endl;
	std::cout << "R" << std::endl << R << std::endl;
	std::cout << "T" << std::endl << T << std::endl;

	cv::Mat I1 = cv::imread(image1File);
	cv::Mat I2 = cv::imread(image2File);

	cv::namedWindow("Left");
	cv::namedWindow("Right");
	cv::imshow("Left", I1);
	cv::imshow("Right", I2);
	cv::waitKey();

	return 0;

}
