#include <iostream>
using namespace std;

class Base { };

class Derived : public Base { };

int main() 
{
    Base b;
    Derived d;

    Base *pb = dynamic_cast<Base*>(&d);        // #1
    Derived *pd = dynamic_cast<Derived*>(&b);  // #2

    return 0;
}
