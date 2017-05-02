#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cstring>

using namespace std;
using namespace cv;
int main( int argc, char** argv ){
    Mat frame;
    //VideoCapture cap("gst-launch-1.0 nvcamerasrc ! video/x-raw(memory:NVMM), width=(int)1280, height=(int)720,format=(string)I420, framerate=(fraction)24/1 ! nvvidconv flip-method=2 ! video/x-raw, format=(string)BGRx ! videoconvert ! 'video/x-raw, format=(string)BGR' ! appsink"); // open the camera
    //VideoCapture cap(-1);
    //VideoCapture cap("gst-launch-1.0 nvcamerasrc ! 'video/x-raw(memory:NVMM), width=(int)1920, height=(int)1080, format=(string)I420, framerate=(fraction)30/1' ! nvtee ! nvvidconv flip-method=2 ! 'video/x-raw(memory:NVMM), format=(string)I420' ! nvoverlaysink -e");
    //VideoCapture cap("nvcamerasrc ! video/x-raw(memory:NVMM), width=(int)320, height=(int)240, format=(string)I420, framerate=(fraction)120/1 ! nvvidconv flip-method=2 ! video/x-raw, format=(string)I420 ! videoconvert ! video/x-raw, format=(string)BGR ! appsink");
    //VideoCapture cap("nvcamerasrc ! video/x-raw(memory:NVMM), width=(int)1280, height=(int)720, format=(string)I420, framerate=(fraction)24/1 ! nvvidconv flip-method=2 ! video/x-raw, format=(string)BGRx ! videoconvert ! 'video/x-raw, format=(string)BGR' ! appsink"); // open the camera


     //VideoCapture cap("nvcamerasrc ! video/x-raw(memory:NVMM), width=(int)2592, height=(int)1944,format=(string)I420, framerate=(fraction)30/1 ! nvvidconv flip-method=2 ! video/x-raw(memory:NVMM), format=(string)I420 ! nvoverlaysink -e ! appsink");


    VideoCapture cap("nvcamerasrc ! video/x-raw(memory:NVMM), width=(int)1280, height=(int)720, format=(string)I420, framerate=(fraction)10/1 ! nvvidconv flip-method=2 ! video/x-raw, format=(string)I420 ! videoconvert ! video/x-raw, format=(string)BGR ! appsink");



    if(!cap.isOpened())
    {
        cout << "video is not opened\n";
        return -1;
    }

    cout << "hhyeo sucess\n"; 

    namedWindow("tracker", 1);

    // get bounding box
    cap >> frame;
    for ( ;; ){
        // get frame from the video
        cap >> frame;
        // stop the program if no more images
        if(frame.rows==0 || frame.cols==0)
        {
            cout << "movie is end\n";
            break;
        }
        // show image with the tracked object
        imshow("tracker",frame);
        //quit on ESC button
        if(waitKey(1)==27)break;
    }
    return 0;
}

