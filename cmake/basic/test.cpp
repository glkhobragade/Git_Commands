#include<iostream>
#include "my_library/header-a.hpp"

using namespace std;

int main()
{
    cout << "My name is ghansham" << endl;
    #ifdef DEB
        cout << "This line is dependent on DEBUG flag" << endl;
    #endif
    cout << sqr(5);
    return 0;
}

