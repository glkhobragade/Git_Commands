#include<iostream>
using namespace std;

extern int p;
int sqr(int n)
{
    cout << "value of p is" << p;  // this line is giving error as the definition could not be found during 
    //linking phase, thus if line is removed alone, the error is solved even though there is mention of extern variable p declared here.
    return n*n;
}
