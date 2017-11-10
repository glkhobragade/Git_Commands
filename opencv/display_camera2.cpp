#include "opencv2/opencv.hpp"
#include <iostream>
 
using namespace std;
using namespace cv;
 
int main(){
 
  // Create a VideoCapture object and open the input file
  // If the input is the web camera, pass 0 instead of the video file name
  VideoCapture cap("Wildlife.wmv"); 
  int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH); 
  int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT); 
    
  // Check if camera opened successfully
  if(!cap.isOpened()){
    cout << "Error opening video stream or file" << endl;
    return -1;
  }
  cout << "Default frame size is " << frame_height << " * " << frame_width;   
    Mat frame(1280,720, CV_8UC3);
    Mat newframe(1280,720,CV_8UC3);
    uchar *frame_ptr = NULL;
    frame_ptr = new uchar[1280*720*3];

  while(1){
 
    // Capture frame-by-frame
    //cap >> frame; or using below line
    bool b = cap.read(frame);

    //int height = frame.size().height;
    //int width = frame.size().width;
    //newframe = frame;  //===> this is a shallow copy thats why faster
    newframe = frame.clone();
    //newframe.data = frame.data;
    //frame_ptr = frame.data;
    //memcpy(newframe.data, frame.data, 1280*720*3); 

    fprintf(stdout, "Size of frame is %d\n", sizeof(frame));
  
    // If the frame is empty, break immediately
    if (frame.empty())
      break;
    //cvtColor(frame, newframe, CV_RGB2GRAY);  
    // Display the resulting frame
    imshow( "Frame", newframe );
 
    // Press  ESC on keyboard to exit
    char c=(char)waitKey(25);
    if(c==27)
      break;
  }
  
  // When everything done, release the video capture object
  cap.release();
 
  // Closes all the frames
  destroyAllWindows();
     
  return 0;
}
