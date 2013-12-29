#include<iostream>
using namespace std;
 
class Test
{
private:
  int x;
  int y;
public:
  Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
  static void fun1() { cout << "Inside fun1()"; }
  static void fun2() { cout << "Inside fun2()"; this->fun1(); }
};
 
int main()
{
  Test obj;
  obj.fun2();
  return 0;
}

/*
2.cpp:12:49: error: invalid use of 'this' outside of a non-static member function
static void fun2() { cout << "Inside fun2()"; this->fun1(); }
                                                ^
1 error generated.
 */
