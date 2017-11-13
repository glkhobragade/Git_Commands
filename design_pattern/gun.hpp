#ifndef _GUN_H_
#define  _GUN_H_

#include<iostream>
class gun
{
    public:
    gun()
    {
        std::cout << "In a gun class consructor"  << std::endl;
    }
    ~gun()
    {
        std::cout << "In a gun class destructor" << std::endl; 
    }
    void fire()
    {
        std::cout << "Gun has fired " << std::endl;
    }
};

#endif
