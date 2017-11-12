#include<iostream>
#include "sqrt.hpp"
#include <unistd.h>

using namespace std;

extern int p;
extern int sq(int num)
{
    sleep(5);
    cout << "The value of p is " << p <<endl;
    return num*num;
}
