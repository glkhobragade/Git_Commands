#include<iostream>

using namespace std;
void foo(int& i)
{
    cout << "\nInside foo()";
    cout << i;
}

void bar(const int& i)
{
    cout << "\nInside bar()";
    cout << i;
}

int main()
{
    std::cout << "\nHello World\n";
    int i=1;
    foo(i);
    //foo(1); This will give an compilation error.
    bar(1);
    return 0;
}
