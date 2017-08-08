#include<iostream>

using namespace std;

template<class T>
void TwiceIt(const T& tData)
{
    tData *= 2;    
    // tData = tData + tData;
}

int main()
{
	int x =int(5);
	TwiceIt(x);
	cout << x;
}
