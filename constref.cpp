#include<iostream>

using namespace std;
void foo(int& i)
{
    cout << "\nInside foo()";
    i++;
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
    cout << "i value:" << i ;
    //foo(1); //This will give an compilation error, as it generate the const int temp object for which such function is not present;
    bar(1);
    return 0;
}
