#include<iostream>
using namespace std;
 
class Test
{
private:
  int x;
  int y;
public:
  Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
  void setX(int a) { x = a; }
  void setY(int b) { y = b; }
  void destroy()  { cout << "Will destroy now\n"; delete this; cout << "Destroy done\n"; }
  void print() { cout << "x = " << x << " y = " << y << endl; }
};
 
int main()
{
  Test obj;
  Test *obj1 = new Test();
  //  obj.destroy();
  //obj.print();
  obj1->destroy(); //this is ok, since objected was created using new. above (onj) is not ok.
  return 0;
}

// http://www.geeksforgeeks.org/delete-this-in-c/
