#include<iostream>

using namespace std;

class base
{
    public:
    base(){cout << "base constrt called" << endl;}
    virtual void see() { cout << "I am in see method" << endl;}
    virtual void walk(){ cout << "I am in base walk" << endl;}
    virtual void walk(int i){cout << "in a param base walk" << endl;}
};


class derived:public base
{
    public:
    derived(){cout << "In a derived constrct" <<endl;}
    void see(){cout << "i am in derived see method" <<endl;}
    //void walk(){ cout << "I am in derived walk" << endl;}
    void walk(int x){ cout << "I am in param derived walk" << endl;} // if you override not all of the overloaded functions in the derived class
    // then other overloaded functions get hidden. they are not present in the derived class, so cannot be called with derived class object
};


int main()
{
    derived d;
    d.see();
    //d.walk();
    d.walk(2);
    cout << "*****************************" <<endl;
    base b;
    b.see();
    b.walk();
    cout << "*****************************" <<endl;
    base *bd = new derived;
    bd->see();
    bd->walk();  // even if the walk() method is hidden in the derived class, it can be called with base class object referring to derived class, then 
    // method in the base class will be called.
    bd->walk(5);
    cout << "*****************************" <<endl;

}
