#include<iostream>

using namespace std;

class A {
protected:
  int num;
};

class B : public A {
};

main () {
  //B * bclass = new B ();
  A a;
  a.num = 10; 
  cout << a.num;
  //bclass->num = 1;
}
