#include<iostream>
using namespace std;
 
class Test
{
private:
  int x;
public:
  Test(int x = 0) { this->x = x; }
  void change(Test *t) { this = t; }
  void print() { cout << "x = " << x << endl; }
};
 
int main()
{
  Test obj(5);
  Test *ptr = new Test (10);
  obj.change(ptr);
  obj.print();
  return 0;
}
/*
compile error
1.cpp:10:31: error: expression is not assignable
  void change(Test *t) { this = t; }

For a class X, the type of this pointer is ‘X* const’.
 */
