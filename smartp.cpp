#include <iostream>
#include <memory>

/* auto_ptr transfer the ownership of the pointer, so another pointer can remove the memory block assigned,
 * thus leaving the earlier pointer becoming dangled, thats why this program is getting crashed.
 * more information on 
 * https://www.codeproject.com/Articles/541067/Cplusplus-Smart-Pointers  */



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
void Fun(auto_ptr<Test> p1 )
{
    cout<<p1->m_a<<endl;
}
//***************************************************************
int main( )
{
    std::auto_ptr<Test> p( new Test(5) ); 
    Fun(p);
    cout<<p->m_a<<endl;
    return 0;
} 
