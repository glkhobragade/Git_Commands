#ifndef __WEAPON_CNTL__
#define __WEAPON_CNTL__


#include<iostream>
#include "weaponInterface.hpp"

using namespace std;

class weaponController
{
    weaponInterface *wIntf;

    public:
    weaponController():wIntf(new weaponMissile())
    {
        cout << "Inside a weaponController constructor" << endl;
    }
    ~weaponController(){delete wIntf;
        cout << "Inside a weaponController destructor" << endl;
    }

    void shootTarget()
    {
        cout << "shootTarget inside weaponController" << endl;
        wIntf->shootTarget();
    }

};


#endif
