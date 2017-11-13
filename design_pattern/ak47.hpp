#ifndef _Ak47_H_
#define _AK47_H_

#include<iostream>
class ak47
{
    public:
    ak47()
    {
        std::cout << "In a ak47 class consructor"  << std::endl;
    }
    ~ak47()
    {
        std::cout << "In a ak47 class desructor"  << std::endl;
    }
    void fire()
    {
        std::cout << "ak47 has fired " << std::endl;
    }
};

#endif
