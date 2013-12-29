#include<iostream>
using namespace std;
 
class Test
{
private:
  int x;
  int y;
public:
  Test (int x = 0, int y = 0) { this->x = x; this->y = y; }
  Test (const Test &t) { cout<<"Copy constructor\n"; }
  Test setX(int a) { cout << "Called setX\n"; x = a; this->print(); return *this; }
  Test setY(int b) { cout << "Called setY\n"; y = b; this->print(); return *this; }
  void print() { cout << "x = " << x << " y = " << y << endl; }
  ~Test() {cout <<"Destructor Test called\n";}
};

class Test1
{
private:
  int x;
  int y;
public:
  Test1 (int x = 0, int y = 0) { this->x = x; this->y = y; }
  Test1 (const Test &t) { cout<<"Copy constructor\n"; }
  Test1* setX(int a) { cout << "Called setX\n"; x = a; this->print(); return this; }
  Test1* setY(int b) { cout << "Called setY\n"; y = b; this->print(); return this; }
  void print() { cout << "x = " << x << " y = " << y << endl; }
  ~Test1() {cout <<"Destructor Test1 called\n";}
};

 
int main()
{
  Test obj1;
  Test a = obj1.setX(10).setY(20);
  obj1.print();
  cout << "-----\n";
  Test1 obj11;
  obj11.setX(10)->setY(20);
  obj11.print();
  cout << "-----\n";

  return 0;
}
