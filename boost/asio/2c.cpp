#include<boost/asio.hpp>
#include <boost/thread/thread.hpp>

#include <iostream>


void F2( int i, float f )
{
        std::cout << "i: " << i << std::endl;
            std::cout << "f: " << f << std::endl;
}

void F1()
{
        std::cout << __FUNCTION__ << std::endl;
}

int main( int argc, char * argv[] )
{
        boost::bind( &F1 )();
        boost::bind( &F2, 42, 3.14f )();
            return 0;
}

