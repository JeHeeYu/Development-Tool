Mat Hist(const Mat& img)
{
	CV_Assert(img.type() == CV_8UC1);             // 전달된 img 영상이 그레이스케일인지 검사

	Mat hist;                                     /*
	int channels[] = { 0 };
	int dims = 1;                                     calHist() 함수에 전달할 인자들
	const int histSize[] = { 256 };
	float graylevel[] = { 0, 256 };
	const float* ranges[] = { graylevel };                              */

	calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);    // img 영상의 히스토그램을 hist 변수에 저장

	return hist;  // hist 반환
}

/* =============== */

Mat HistGraph(const Mat& hist)
{
	CV_Assert(hist.type() == CV_32FC1);          // 전달된 영상이 그레이스케일인지 검사
	CV_Assert(hist.size() == Size(1, 256));      // 전달된 hist 행렬이 256개의 빈으로 구성되어 있는지 검사

	double histMax;
	minMaxLoc(hist, 0, &histMax);                // hist 행렬 원소의 최대값을 histMax 변수에 저장

	Mat imgHist(100, 256, CV_8UC1, Scalar(255));    // for문을 이용하여 그래프를 그림
	for (int i = 0; i < 256; i++) {
		line(imgHist, Point(i, 100), Point(i, 100 - cvRound(hist.at<float > (i, 0) * 100 / histMax)), Scalar(0));
	}

	return imgHist;
}
