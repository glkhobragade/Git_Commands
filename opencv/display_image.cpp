#include <opencv2/highgui/highgui.hpp>
#include <iostream>
 
using namespace cv;
using namespace std;
 
int main( )
{
 
       Mat image;
 
       // LOAD image
       image = imread("image1.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file "image.jpg".
              //This file "image.jpg" should be in the project folder.
              //Else provide full address : "D:/images/image.jpg"
 
       if(! image.data )  // Check for invalid input
       {
              cout <<  "Could not open or find the image" << std::endl ;
              return -1;
       }
 
       //DISPLAY image
       namedWindow( "flower", CV_WINDOW_AUTOSIZE ); // Create a window for display.
       imshow( "flower", image ); // Show our image inside it.
 
       //SAVE image
       imwrite("result.jpg",image);// it will store the image in name "result.jpg"
 
       waitKey(0);                       // Wait for a keystroke in the window
       return 0;
}
