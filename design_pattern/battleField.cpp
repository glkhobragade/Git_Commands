#include<iostream>
#include "weaponController.hpp"

using namespace std;

class BattlefieldSoftware
{
    private:
        weaponController* wc;
    public:
        BattlefieldSoftware() : wc(new weaponController()) {
            cout << "Inside the BattlefieldSoftware constructor" << endl;
        }
        ~BattlefieldSoftware() { delete wc;
            cout << "Inside the BattlefieldSoftware destructor" << endl;
        }

        void shootTarget()
        {
            cout << "shootTarget inside BattlefieldSoftware" << endl;
            wc->shootTarget();
        }
};

int main()
{
    BattlefieldSoftware* bf = new BattlefieldSoftware();
    cout << "Battle fied software object is created." << endl;
    bf->shootTarget();
    delete bf;
}

