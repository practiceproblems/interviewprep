#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A) {
  // write your code in C++98 
  vector<int> hash;
  hash.reserve(A.size());
  for (vector<int>::const_iterator i = A.begin(); i!=A.end() ; ++i) {
    hash.push_back(*i);
    hash.back() = -1;
  }
    
  for (vector<int>::const_iterator i = A.begin(); i!=A.end() ; ++i) {
    if ( (*i > A.size()) || (*i < 1) || (hash[*i-1]!=-1))  return 0;  
    hash[*i-1] = 0;
  }
  return 1;
}


int main(){
  vector<int> A;
  A.push_back(4);
  A.push_back(1);
  A.push_back(3);
  A.push_back(2);
  cout <<solution(A) << endl;
  return 0;
}
