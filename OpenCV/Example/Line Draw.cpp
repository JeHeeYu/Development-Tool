#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
  Mat img(480, 620, CV_8UC3, Scalar(255, 255, 255));
  
  line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));
	line(img, Point(50, 100), Point(200, 100), Scalar(255, 0, 255), 3);
	line(img, Point(50, 150), Point(200, 150), Scalar(255, 0, 0), 10);

	imshow("img", img);


	arrowedLine(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255), 1, LINE_4);
	arrowedLine(img, Point(50, 100), Point(200, 100), Scalar(255, 0, 255), 1, LINE_8);
	arrowedLine(img, Point(50, 150), Point(200, 150), Scalar(255, 0, 0), 1, LINE_8, 0, 0.05);

	imshow("img", img);
  
  drawMarker(img, Point(50, 50), Scalar(255, 0, 0), MARKER_CROSS);
	drawMarker(img, Point(50, 100), Scalar(0, 255, 0), MARKER_TILTED_CROSS);
	drawMarker(img, Point(50, 150), Scalar(0, 0, 255), MARKER_STAR);
	drawMarker(img, Point(50, 200), Scalar(0, 255, 255), MARKER_DIAMOND);
	drawMarker(img, Point(50, 250), Scalar(255, 0, 255), MARKER_SQUARE);
	drawMarker(img, Point(50, 300), Scalar(255, 255, 0), MARKER_TRIANGLE_UP);
	drawMarker(img, Point(50, 350), Scalar(0, 0, 0), MARKER_TRIANGLE_DOWN);

	imshow("img", img);

	waitKey(0);
}
