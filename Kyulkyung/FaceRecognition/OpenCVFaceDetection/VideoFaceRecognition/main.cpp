#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#ifndef _MSC_VER
#include <sys/ipc.h>
#include <sys/param.h>
#endif // !_MSC_VER

using namespace std;
using namespace cv;

#define CAM_WIDTH 1280
#define CAM_HEIGHT 720

/** Function Headers */
void detectAndDisplay(Mat frame, String sec);

/** Global variables */
cv::String face_cascade_name;
cv::String haarcascade_dir = "C:\\OpenCv\\opencv-3.4.0\\sources\\data\\haarcascades\\haarcascade_frontalface_alt.xml";
cv::String lbpcascade_dir = "C:\\OpenCV\\opencv-3.4.0\\sources\\data\\lbpcascades\\lbpcascade_frontalface_improved.xml";
cv::String hogPedestrian_dir = "C:\\OpenCV\\opencv-3.4.0\\sources\\data\\hogcascades\\hogcascade_pedestrians.xml";
cv::CascadeClassifier face_cascade;
cv::String window_name = "Face detection";
int TOTAL_FRAME;
/** @function main */

int main(void) {

	//face_cascade_name = "C:\\OpenCv\\opencv-3.4.0\\sources\\data\\haarcascades\\haarcascade_frontalface_alt.xml";
	//face_cascade_name = haarcascade_dir;
	//face_cascade_name = hogPedestrian_dir;

	face_cascade_name = lbpcascade_dir;
	if (!face_cascade.load(face_cascade_name)) { printf("--(!)Error loading face cascade\n"); return -1; };

	cv::Mat frame;
	int key;
	char VideoName[] = "pikaboo_high.mp4";
	
	cv::VideoCapture* m_Capture = new cv::VideoCapture(VideoName);

	TOTAL_FRAME = m_Capture->get(cv::CAP_PROP_FRAME_COUNT);
	int FPS = m_Capture->get(cv::CAP_PROP_FPS);
	cv::Mat img_list;
	for (int i = 0; i < (int)TOTAL_FRAME * 4; i++) {
		m_Capture->set(cv::CAP_PROP_POS_FRAMES, (int) i * 0.25  * FPS);
		m_Capture->read(img_list);
		IplImage tmp_ = img_list;
		cv::String sec_ = to_string(i * 0.25  * FPS);
		detectAndDisplay(img_list, sec_);

		key = cvWaitKey(30);
		if (key == 27) break;//ESC key
	}

	return 0;

}

/*void CaptureVideoFrame() {
	cvNamedWindow("win", CV_WINDOW_AUTOSIZE);
	capture = cvCaptureFromFile(fileName);
	CvCapture *capture;
	IplImage *img;
	img = cvQueryFrame(tmp_);
	frame = cvarrToMat(img);
	namedWindow("image", WINDOW_AUTOSIZE);
	imshow("image", img_list);
	waitKey(30);
	cv::String file_name = "C:\\Users\\doomsheart\\Documents\\Dev\\Kyulkyung\\CNN\\OpenCVProject\\OpenCV_Tutorial_1_LoadIMG\\outputFiles\\CAP_";
	bool a = imwrite(file_name + std::to_string(i) + ".jpg", img_list);
	cout << file_name + std::to_string(i) + ".jpg" << "\n";
}*/


/** @function detectAndDisplay */
void detectAndDisplay(Mat frame_, String sec)
{
	Mat frame;
	resize(frame_, frame, frame.size(), 0.5, 0.5);
	std::vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	//cvtColor(frame, frame_gray, COLOR_BGR2BGR);
	equalizeHist(frame_gray, frame_gray);

	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
	for (size_t i = 0; i < faces.size(); i++)
	{
		//Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
		Point face_pt_1(faces[i].x, faces[i].y);
		Point face_pt_2(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
		//C++: void rectangle(InputOutputArray img, Point pt1, Point pt2, const Scalar& color, int thickness = 1, int lineType = LINE_8, int shift = 0)
		rectangle(frame, face_pt_1, face_pt_2, Scalar(0, 0, 255),1,0);
		//C++: void ellipse(InputOutputArray img, Point center, Size axes, double angle, double startAngle, double endAngle, const Scalar& color, int thickness = 1, int lineType = LINE_8, int shift = 0)
		//ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2),
			//0, 0, 360, Scalar(0, 0, 255), 4, 8, 0);
	//C:\Users\doomsheart\Documents\Dev\Kyulkyung\FaceRecognition\OpenCVFaceDetection
		cv::String file_name = "C:\\Users\\doomsheart\\Documents\\Dev\\Kyulkyung\\FaceRecognition\\OpenCVFaceDetection\\pikaboo\\";
		/*try {

		}*/
		faces[i].x *= 2;
		faces[i].y *= 2;
		faces[i].height *= 2;
		faces[i].width *= 2;

		imshow(window_name, frame_(faces[i]));
		/*bool a = imwrite(file_name + sec + "_" + to_string(i) +".jpg", frame_(faces[i]));
		if (a) {
			printf("%s_%s.jpg\n", sec, to_string(i));
		}
		else {
			printf("error occured\n");
		}*/
		//imwrite();
	}
	//imshow(window_name, frame);
}