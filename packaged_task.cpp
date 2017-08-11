#include <iostream>
#include <cmath>
#include <thread>
#include <future>
#include <functional>
 
// unique function to avoid disambiguating the std::pow overload set
int f(int x, int y) { return std::pow(x,y); }
 
void task_lambda()
{
    std::packaged_task<int(int,int)> task([](int a, int b) {
        return std::pow(a, b); 
    });
    std::future<int> result = task.get_future();
 
    task(2, 3);
    std::cout << "task_lambda:\t" << result.get() << '\n';

    /*
     * //The below 2 statements can't be added as those throws an exception, as below
     *
     * task(2, 1);  =====> what():  std::future_error: Promise already satisfied
     * std::cout << "task_lambda 2:\t" << result.get() << '\n';  ====>  what():  std::future_error: No associated state
    */
}
 
void task_bind()
{
    std::packaged_task<int()> task(std::bind(f, 2, 4));
    std::future<int> result = task.get_future();
 
    task();
 
    std::cout << "task_bind:\t" << result.get() << '\n';

    /*
     * //The below 2 statements can't be added as those throws an exceptions as above:
     *
    //task();
    //std::cout << "task_bind:\t" << result.get() << '\n';

    */
}
 
void task_thread()
{
    std::packaged_task<int(int,int)> task(f);
    std::future<int> result = task.get_future();
 
    std::thread task_td(std::move(task), 2, 5);
    task_td.join();
 
    std::cout << "task_thread:\t" << result.get() << '\n';

    /* check this properly, the exception is different here
     * std::thread task_td2(std::move(task), 2, 5); ====>   what():  std::future_error: No associated state
     * task_td2.join();
 
    std::cout << "task_thread:\t" << result.get() << '\n'; ====>   what():  std::future_error: No associated state
    */
}
 
int main()
{
    task_lambda();
    task_bind();
    task_thread();
}
