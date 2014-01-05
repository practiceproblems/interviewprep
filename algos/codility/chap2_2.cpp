#include <set>
int solution(int X, vector<int> &A) {
  // write your code in C++98
  set<int> hash;
  for (int i = 1; i<= X ; ++i)
    hash.insert(i);
    
  for (unsigned int i = 0; i< A.size() ; ++i){
    if (hash.find(A[i]) != hash.end()) hash.erase(A[i]);
    if (hash.empty()) return i;
  }
  return -1;
}
