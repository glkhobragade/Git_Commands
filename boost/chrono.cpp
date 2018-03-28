#include <iostream>
#include <chrono>
 
constexpr auto year = 31556952ll; // seconds in average Gregorian year
 
int main()
{
    using shakes = std::chrono::duration<int, std::ratio<1, 100000000>>;
    using jiffies = std::chrono::duration<int, std::centi>;
    using microfortnights = std::chrono::duration<float, std::ratio<14*24*60*60, 1000000>>;
    using nanocenturies = std::chrono::duration<float, std::ratio<100*year, 1000000000>>;
 
    std::chrono::seconds sec(1);
 
    std::cout << "1 second is:\n";
 
    // integer scale conversion with no precision loss: no cast
    std::cout << std::chrono::microseconds(sec).count() << " microseconds\n"
              << shakes(sec).count() << " shakes\n"
              << jiffies(sec).count() << " jiffies\n";
 
    // integer scale conversion with precision loss: requires a cast
    std::cout << std::chrono::duration_cast<std::chrono::minutes>(sec).count()
              << " minutes\n";
 
    // floating-point scale conversion: no cast
    std::cout << microfortnights(sec).count() << " microfortnights\n"
              << nanocenturies(sec).count() << " nanocenturies\n";
}
