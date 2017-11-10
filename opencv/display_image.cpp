#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( )
{

    Mat im;
    Mat from_ch(1289, 1980, CV_8UC3);
    uchar *imc = NULL;

    // LOAD im
    im = imread("image1.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file "image.jpg".
    //This file "image.jpg" should be in the project folder.
    //Else provide full address : "D:/images/image.jpg"

    cout << "Heigh and widht of image is " << im.size().height << "  " << im.size().width << endl;
    cout << "size of na image is" << im.size() << endl;
    cout << "size of an image in bytes is" << im.step[0] * im.rows << endl;
    unsigned long int sz = im.step[0] * im.rows;
    if(! im.data )  // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    imc = new uchar[sz]; 
    imc = im.data;
    memcpy(from_ch.data, imc, (im.size().height * im.size().width * 3));
    //from_ch.data = imc;

    //DISPLAY image
    namedWindow( "flower", CV_WINDOW_AUTOSIZE ); // Create a window for display.
    namedWindow( "flower_copy", CV_WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "flower", im ); // Show our image inside it.
    imshow( "flower_copy", from_ch ); // Show our image inside it.

    //SAVE image
    imwrite("result.jpg",im);// it will store the image in name "result.jpg"

    waitKey(0);                       // Wait for a keystroke in the window
    return 0;
}
