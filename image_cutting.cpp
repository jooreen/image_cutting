#define _CRT_SECURE_NO_WARNINGS
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace cv;

FILE* fp;

int main() {

	Mat img = imread("Lenna.ppm", IMREAD_COLOR);
	fp = fopen("result.ppm", "w");

	int M, N;
	int k = 0;
	M = img.rows;
	N = img.cols;

	fprintf(fp, "P3\n");
	fprintf(fp, "256 256\n");
	fprintf(fp, "255\n");

	int intensity_b = 0;
	int intensity_g = 0;
	int intensity_r = 0;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (k / M < 20 || k / N > N - 20 || k % M < 20 || k % N < N - 20)
			{
				intensity_b = 255;
				intensity_g = 255;
				intensity_r = 255;
			}

			else
			{
				intensity_b = img.at<Vec3b>(i, j)[0];
				intensity_g = img.at<Vec3b>(i, j)[1];
				intensity_r = img.at<Vec3b>(i, j)[2];
			}

			k++;

			fprintf(fp, "%3d %3d %3d\n", intensity_r, intensity_g, intensity_b);
		}
	}

	waitKey(0);
	fclose(fp);
	return 0;
}
