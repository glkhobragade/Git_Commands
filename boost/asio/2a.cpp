#include<boost/asio.hpp>
#include <boost/thread/thread.hpp>

#include <iostream>

void F1()
{
        std::cout << __FUNCTION__ << std::endl;
}

int main( int argc, char * argv[] )
{
        boost::bind( &F1 );
            return 0;
}

