#include "template.hpp"

using namespace std;

int main()
{
    test<int> t;
    shared_ptr<struct name<int>> gh;
    gh = t.getX();

    cout << gh->p << gh->q << gh->r << endl;
    //cout << gh.p << gh.q << gh.r <<endl;
}
