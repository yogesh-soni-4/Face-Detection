#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// to read image from the directory
/*void main() {

	string path = "YOGI PIC.png";
	Mat img = imread(path); // Mat or is the datatype stands for Matrix of the image its just like matrix or numpy array in python
	imshow("Frame", img);
	waitKey(0); // delay
}*/



// to read video from webcam
/*void main() {
	VideoCapture video(0);
	Mat img;
	while (true) {
		video.read(img);
		imshow("Frame", img);
		waitKey(1);
		waitKey(20); // means takes one frame in 2o miliseconds

	}
}*/


// FACE DETECTION IN C++
void main() {
	VideoCapture video(0);
	Mat img;
	CascadeClassifier faceDetect;
	faceDetect.load("haarcascade_frontalface_default.xml");
	while (true) {
		video.read(img);

		vector<Rect> faces; // to store the position of 4 points of rectangel to detect the face
		
		faceDetect.detectMultiScale(img, faces, 1.3, 5); // scale factor, minNeighbours
		
		cout << faces.size() << endl; // to print the number of faces on the terminal
 
		for (int i = 0; i < faces.size(); i++) {
			// to plot the rectangle shape around the detects face
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
			// tl->top left, br-> bottom right
			// (50,50,255) is RGB for red color
			// 3 is the width of the lines of the rectangle

			// to print the number of faces on the screen
			putText(img, to_string(faces.size())+" FACES FOUND", Point(10, 60), FONT_HERSHEY_DUPLEX, 1, Scalar(50, 50, 255));
		}
		imshow("Frame", img);
		waitKey(1);
	}
}

