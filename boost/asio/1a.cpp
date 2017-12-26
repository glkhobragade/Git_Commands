#include<boost/asio.hpp>
#include<thread>
#include <iostream>

int main()
{
	boost::asio::io_service io_service;
	io_service.run();
	std::cout << "Do you reckon this line displays?" << std::endl;
	return 0;
}
