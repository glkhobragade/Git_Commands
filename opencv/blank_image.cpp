#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, const char** argv )
{
     Mat im(500, 1000, CV_8UC3, Scalar(0,0,250)); //create an image ( 3 channels, 8 bit image depth, 500 high, 1000 wide, (0, 0, 100) assigned for Blue, Green and Red plane respectively. )

     if (im.empty()) //check whether the image is loaded or not
     {
          cout << "Error : Image cannot be loaded..!!" << endl;
          //system("pause"); //wait for a key press
          return -1;
     }
    cout << "image size is " << im.size() << endl;
    cout << "size of an image in bytes is" << im.step[0] * im.rows << endl;
    cout << "total elements in mat is " << im.total() << endl;
     namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
     imshow("MyWindow", im); //display the image which is stored in the 'im' in the "MyWindow" window

     waitKey(0);  //wait infinite time for a keypress

     destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

     return 0;
}
