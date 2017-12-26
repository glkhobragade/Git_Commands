#include<iostream>
#include "pimpl.hpp"
using namespace std;

class myclass
{
    public:
       void  my_function()
        {
            cout << "Inside my_function" << endl;
            impl->functionx(12); 
        }

        myclass(): impl(new pimpl){}
    private:
        pimpl * impl;
};

int main()
{
    myclass x;
    x.my_function();
    return 0;
}
