#ifndef _WINTF_
#define _WINTF_

#include<iostream>
#include "gun.hpp"
#include "missile.hpp"
#include "ak47.hpp"

using namespace std;

class weaponInterface
{
    public:
        weaponInterface()
        {
            cout << "In weaponInterface constructor " << endl;
        }
        virtual ~weaponInterface()
        {
            cout << "In weaponInterface destructor " << endl;
        }
        virtual void shootTarget() = 0;
};


class weaponGun : public weaponInterface
{
    gun *g;

    public:
    weaponGun():g(new gun()) {
        cout << "Inside the weaponGun constructor" << endl;
    }
    ~weaponGun(){delete g;
        cout << "Inside the weaponGun destructor" << endl;
    }
    void shootTarget()
    {
        std::cout << "shootTarget inside weaponGun Interface" << endl;
        g->fire();
    }
};

class weaponAk47 : public weaponInterface
{
    ak47 *ak;

    public:
    weaponAk47():ak(new ak47()) {

        cout << "Inside the weaponAk47 constructor" << endl;
    }
    ~weaponAk47(){delete ak;
        cout << "Inside the weaponAk47 destructor" << endl;
    }
    void shootTarget()
    {
        std::cout << "shootTarget inside weaponAk47 Interface" << endl;
        ak->fire();
    }
};

class weaponMissile : public weaponInterface
{
    missile *m;

    public:
    weaponMissile():m(new missile()) {
        cout << "Inside the weaponMissile constructor" << endl;
    }
    ~weaponMissile(){delete m;
        cout << "Inside the weaponMissile constructor" << endl;
    }
    void shootTarget()
    {
        std::cout << "shootTarget inside weaponMissile Interface" << endl;
        m->fire();
    }
};


#endif
