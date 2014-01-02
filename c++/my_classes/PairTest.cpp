#include "Pair.h"
#include <iostream>
using namespace std;

int main(){
  Pair<int,int> pint1(10,-10), pint2(20,-20), pint3(30,-30), pint0;
  pint0.print(cout);  
  pint1.print(cout);  
  pint2.print(cout);  
  pint3.print(cout);  
  cout <<"----\n";
  pint0 = pint3;
  pint0.print(cout);
  pint0 += pint1;
  pint0.print(cout);
  Pair<int, int> padd = pint1 + pint2;
  padd.print(cout);
  (padd == pint0) ? cout << "Equal\n" : cout << "Not equal\n";
  padd += pint1;
  padd.print(cout);
  (padd == pint0) ? cout << "Equal\n" : cout << "Not equal\n";
}

