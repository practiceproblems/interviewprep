#include <iostream>
using namespace std;

class Base{
 public:
  Base() { cout << "Base constructor\n"; }
  virtual ~Base() { cout << "Base destructor\n";}
  Base (const Base &rhs) { cout << "Base copy constructor\n";}
  virtual void fun() { cout << "Base fun\n";}
  
};

class Derived1: public Base{
 public:
  Derived1() { cout << "Derived1 constructor\n"; }
  virtual ~Derived1() { cout << "Derived1 destructor\n";}
  Derived1 (const Derived1 &rhs) { cout << "Derived1 copy constructor\n";}
  virtual void fun() { cout << "Derived1 fun\n";}
  
};

class Derived2: public Base{
 public:
  Derived2() { cout << "Derived2 constructor\n"; }
  virtual ~Derived2() { cout << "Derived2 destructor\n";}
  Derived2 (const Derived2 &rhs) { cout << "Derived2 copy constructor\n";}
  virtual void fun() { cout << "Derived2 fun\n";}
  
};


int main(){
  Base b1, b2;
  cout << "---\n";
  Derived1 d1;
  cout << "---\n";
  Derived2 d2;
  cout << "---\n";
  Base *b1ptr = new Base();
  cout << "---\n";
  Base *b2ptr = new Derived1();
  cout << "---\n";
  b1ptr->fun();
  cout << "---\n";
  b2ptr->fun();
  cout << "---\n";
  /*
  // error: cannot initialize a variable of type 'Derived2 *' with an rvalue of type 'Base *'
  Derived2 * dptr = new Base();
  dptr->fun();
  */
  // Derived1 *dptr1 = new Derived2(); --error
  Base b3(b1);
  cout <<"---\n";
  Derived2 d22(d2); // base ctr first then Derived copy ctr. no derived constructor.
  cout <<"---\n";
  Derived2 d23 = d22;
  cout <<"All done... Destructing now\n";
  return 0;
}
