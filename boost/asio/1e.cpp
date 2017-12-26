#include<boost/asio.hpp>
#include<thread>
#include <iostream>

int main( int argc, char * argv[] )
{
    boost::asio::io_service io_service;
    std::shared_ptr<boost::asio::io_service::work> work( new boost::asio::io_service::work(io_service) );


    // here we have used shared pointer to work, so that we can reset the work.
        work.reset();
        io_service.run();
        std::cout << "Does this line gets displayed " << std::endl;

    return 0;
}
