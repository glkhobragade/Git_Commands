#include<boost/asio.hpp>
#include <boost/thread/thread.hpp>

#include <iostream>
class MyClass
{
    public:
        void F3( int i, float f )
        {
            std::cout << "i: " << i << std::endl;
            std::cout << "f: " << f << std::endl;
        }
};

int main( int argc, char * argv[] )
{
    MyClass c;;
    boost::bind( &MyClass::F3, &c, 42, 3.14f )();
    std::cout << sizeof(c) << std::endl;
    return 0;
}
