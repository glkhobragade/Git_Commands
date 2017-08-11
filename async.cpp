#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
#include <unistd.h>

/* Kindly check: http://jakascorner.com/blog/2016/02/futures.html */

int functionf(int x, int y)
{
    sleep(1);
    return std::pow(x,y);
}

template <typename RAIter>
int parallel_sum(RAIter beg, RAIter end)
{
    auto len = end - beg;
    if (len < 1000)
        return std::accumulate(beg, end, 0);
 
    RAIter mid = beg + len/2;
    auto handle = std::async(std::launch::async,
                             parallel_sum<RAIter>, mid, end);
    int sum = parallel_sum(beg, mid);
    return sum + handle.get();
}
 
int main()
{
    //std::vector<int> v(10000, 1);
    //std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';
    auto result = std::async(std::launch::async, functionf, 2, 3);

    /* If we dint specify the policy then the function will run in the same thread as caller, kindly follow the link at top to understand it properly*/
    std::cout << "The result is" << result.get(); // This is a blocking call, unless value is not returned from the function.
   // std::cout << "The result is" << result.get(); // This is will throw an exception: ====>   what():  std::future_error: No associated state
}
