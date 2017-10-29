#include<iostream>

using namespace std;

int main()
{
    cout << sizeof(int)  << " " << sizeof(float) << endl;
    unsigned int x = 3333333333;
    float f = *((float *)&x);
    float y = x; 
    unsigned char c = *((char *)&x);

    cout << x << " " << f << " " << y << " " << (unsigned int)c << endl;
    return 0;
}
