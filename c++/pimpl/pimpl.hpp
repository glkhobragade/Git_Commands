#include<iostream>
using namespace std;

class pimpl
{
    public:
        pimpl():x(10){}
        void functionx(int x)
        {
            cout << "This is function of pimpl class" << endl;
        }

    int x;
};

