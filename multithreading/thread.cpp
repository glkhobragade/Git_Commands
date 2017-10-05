#include <iostream>
#include <thread>
 
void thread_function()
{
    for(int i = 0; i < 10; i++)
        std::cout<<"thread function Executing"<<std::endl;
}
 
class DisplayThread
{
public:
    void operator()()     
    {
        for(int i = 0; i < 10; i++)
            std::cout<<"Display Thread Executing"<<std::endl;
            fflush(stdout);
    }
};

auto lamda_func = []{
             for(int i = 0; i < 10; i++)
                 std::cout<<"Thread in lambda function"<<std::endl;
                 fflush(stdout);
             };
 
int main()  
{
    
    std::thread threadObj1(thread_function);
    std::thread threadObj2((DisplayThread()));  // kindly mind how the arguements are being passed, dont skip round bracket... try it.
    std::thread threadObj3(lamda_func);
    for(int i = 0; i < 100; i++)
        std::cout<<"Display From MainThread"<<std::endl;

    threadObj1.join();    
    threadObj2.join();    
    threadObj3.join();    
    std::cout<<"Exit of Main function"<<std::endl;
    return 0;
}
