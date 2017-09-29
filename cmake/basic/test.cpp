#include<iostream>

using namespace std;

int main()
{
    cout << "My name is ghansham" << endl;
    #ifdef DEB
        cout << "This line is dependent on DEBUG flag" << endl;
    #endif
    return 0;
}

