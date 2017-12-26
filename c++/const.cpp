#include<iostream>

using namespace std;


int main()
{
    const int i = 5 ;

    int x = 1;
    int y = 2;

    const int *ciptr;// the pointee cant be changed, but pointer;
    ciptr = &x;
    cout << i  << endl;
    cout << x << endl;
    cout << *ciptr << endl;

    //*ciptr = 3;  
    cout << x << endl;


    ciptr = &y;
    cout << *ciptr << endl;
    
    int * const cptr = &x; // the pointer cant be changed, but pointee thats why it has to be initialised as soon as declared;
    cout << *cptr << endl;

    *cptr = 88;
    cout << *cptr << endl;
    cout << x << endl;

    //cptr = &y;  // pointee can be changed, but pointer cant i.e it cant point to another variable.

    int r = 11;
    int t = 12;
    int &s = r;
    cout << s << endl;

    s = t;   // this will also change the value of the reference variable refered by s;
    cout << s << endl;
    cout << r << endl;

    int m = 33;
    int n = 44;
    cout << "===============" << endl;
    const int &l = m;
    cout << l << endl;
    
    //l = n;  // l is an const ref, so it cant give reference to another variable, so this will give an compilation error.
    return 0;
}
