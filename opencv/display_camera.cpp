#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <unistd.h>

using namespace cv;

int main( int argc, const char** argv )
{
    VideoCapture cap;
    cap.open("Wildlife.wmv");
    int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH); 
    int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT); 

    cap.set(CV_CAP_PROP_FRAME_WIDTH,frame_width);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT,frame_height);
    if (!cap.isOpened()) {
        fprintf(stderr, "Could not open video stream\n");
        return 1;
    }
    cv::Mat frame;
    cv::Mat flipped_frame;
    while(1)
    {
        cap >> frame;
        fprintf(stdout, "Size of frame is %d\n", sizeof(frame));

        if (!frame.empty()) {
            fprintf(stderr, "Could not capture frame correctly\n");
        }
        CvMat cvframe = frame;
        cvShowImage("cam2image", &cvframe);
        cv::waitKey(25);
        //sleep(1);
    }
    return 0;
}
