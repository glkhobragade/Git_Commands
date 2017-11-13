// CPP program without virtual destructor 
// causing undefined behavior
#include<iostream>
 
using namespace std;
 
class base {
  public:
    base()     
    { cout<<"Constructing base \n"; }
    virtual ~base()
    { cout<<"Destructing base \n"; }     
};
 
class derived: public base {
  public:
    derived()     
    { cout<<"Constructing derived \n"; }
    ~derived()
    { cout<<"Destructing derived \n"; }
};
 
int main(void)
{
  derived *d = new derived();
  delete d;
  cout << "derived object is destroyed " << endl;
  cout << endl;

  base *b = new base();
  delete b;
  cout << "base object is destroyed " << endl;
  cout << endl;

  base *c = new derived();
  delete c;
  cout << "base having derived object is destroyed " << endl;
  cout << endl;



  return 0;
}
