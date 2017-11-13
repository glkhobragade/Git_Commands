#ifndef _MISSILE_H_
#define _MISSILE_H_

#include<iostream>
class missile
{
    public:
    missile()
    {
        std::cout << "In a missile class consructor"  << std::endl;
    }
    ~missile()
    {
        std::cout << "In a missile class desructor"  << std::endl;
    }
    void fire()
    {
        std::cout << "missile has fired " << std::endl;
    }
};

#endif
