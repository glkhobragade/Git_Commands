#include<iostream>
#include <typeinfo>

using namespace std;
/*
 * In summary, virtual functions are implemented using a table of function pointers, called the vtable. There is one entry in the table per virtual function in the class. This table is created by the constructor of the class. When a derived class is constructed, its base class is constructed first which creates the vtable. If the derived class overrides any of the base classes virtual functions, those entries in the vtable are overwritten by the derived class constructor.
 * This is why you should never call virtual functions from a constructor, and that's because the vtable entries for the object may not have been set up by the derived class constructor yet, so you might end up calling base class implementations of those virtual functions */
 
// lets try above statements 
class employee
{
    public:
    employee(){cout << "employee constrt called" << endl;}
    virtual ~employee(){cout << "employee destrt called" << endl;}
    void see() { cout << "I am in employee see " << endl;}
    virtual void walk(){ cout << "I am in employee walk" << endl;}
    virtual void walk(int i){cout << "in a param employee walk" << endl;}
    virtual void salary(){cout << "Employee salary is 5000" << endl;}
};


class manager:public employee
{
    public:
    manager(){cout << "In a manager constrct" <<endl; }
    virtual ~manager(){cout << "In a manager destrct" <<endl;}
    void see(){cout << "i am in manager see " <<endl;}
    //void walk(){ cout << "I am in manager walk" << endl;}
    void walk(int x){ cout << "I am in param manager" << endl;} // if you override not all of the overloaded functions in the manager class
    // then other overloaded functions get hidden. they are not present in the manager class, so cannot be called with manager class object
    virtual void salary(){cout << "Manager salary is 20000 " << endl;}
    void hire(){ cout << "Hire is called" << endl;}
};


class multi_manager:public manager
{
    public:
        multi_manager(){cout << "In a mulit manager constrct" <<endl;}
        ~multi_manager(){cout << "In a mutli manager destrct" <<endl;}
};

//upcast and downcast;


void salary(employee *b)
{
    b->salary();
    //manager * mp = dynamic_cast<manager*>(b);

    if(typeid(b) == typeid(manager))
    {
        manager *p = (manager*)b;
        p->hire();
    }
}

int main()
{

    // int * b = new int(5)
    std::cout << "\n===============\n";
    //employee e;
    //manager m;
    //salary(&e);
    //salary(&m);

    employee *e1 = new manager ;
    e1->walk();
    salary(e1);

    manager m;
    m.walk();



/*
    derived d;
    d.see();
    //d.walk();
    d.walk(2);
    checkUpcasting(&d);
    cout << "*****************************" <<endl;

    base b;
    b.see();
    b.walk();
    checkUpcasting(&b);
    cout << "*****************************" <<endl;

    base *bd = new derived;
    bd->see();
    bd->walk();  // even if the walk() method is hidden in the derived class, it can be called with base class object referring to derived class, then 
    // method in the base class will be called.
    bd->walk(5);
    checkUpcasting(bd);
    delete bd;
    cout << "*****************************" <<endl;
    cout << "*****************************" <<endl;
    cout << "*****************************" <<endl;

    multi_derived mld;
    mld.see();
    mld.walk(4);
    checkUpcasting(&mld);
    //mld.walk();  // let try this as this method is not present in parent class, but grandparent class, get compilation error
    cout << "*****************************" <<endl;
    cout << "*****************************" <<endl;
    cout << "*****************************" <<endl;


    base *bmld = new multi_derived;
    bmld->see();
    bmld->walk(6);
    bmld->walk();  // let try this here, as the multi derived class dont have this method, it checks in the base class and run that method
    checkUpcasting(bmld);
    cout << "*****************************" <<endl;
    cout << "*****************************" <<endl;
    cout << "*****************************" <<endl;

    derived *db = new multi_derived;
    db->see();
    db->walk(8);
    //db->walk();  // let try this here as well, as this method is not present in parent class, but grandparent class,
                // this wont work as there is not walk() method in derived class
    checkUpcasting(db);
    cout << "*****************************" <<endl;
    cout << "*****************************" <<endl;
    cout << "*****************************" <<endl;

    */

}
