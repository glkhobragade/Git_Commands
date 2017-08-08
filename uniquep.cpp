#include <iostream>
#include <memory>
 

using namespace std;
//***************************************************************
class Test
{
    public:
    Test(int a = 0 ) : m_a(a)
    {
    }
    ~Test( )
    {
        cout<<"Calling destructor"<<endl;
    }
    public:
        int m_a;
};


//***************************************************************
void Fun(unique_ptr<Test>& p1 )
{
    cout<<p1->m_a<<endl;
}
//***************************************************************
int main( )
{
    std::unique_ptr<Test> p( new Test(5) ); 
    unique_ptr<Test> p2 = move(p);
    // or it can be done in following way,
    //unique_ptr<Test> p2;
    //p2 = move(p);


    // Fun(p); This  will give an error: read https://stackoverflow.com/questions/30905487/how-can-i-pass-unique-ptr-into-a-function
    //Fun(p);
    // Fun(move(p)) ==> this will associate with definition void Fun(unique_ptr<Test> p1 ), but the pointer can't be used afterwards in calling function
    // as the ownership has moved to funciton.
    cout<<p2->m_a<<endl;
    return 0;
} 
