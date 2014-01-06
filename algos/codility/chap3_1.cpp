// Score 100/100

// you can also use includes, for example:
// #include <algorithm>
int solution(vector<int> &A) {
  // write your code in C++98
  vector<int> suffix_sums;
  suffix_sums.reserve(A.size());
  unsigned int so_far = 0;
  for (unsigned int i =0; i< A.size() ; ++i){
    if ( 1 == A[i] ){
      ++so_far;
    }
    suffix_sums.push_back(so_far);
  }
  unsigned long long tot = 0;
  for (unsigned int i =0; i< A.size() ; ++i){
    if ( 0 == A[i] ){
      tot +=  (suffix_sums[A.size()-1] - suffix_sums[i]);
      if (tot >1000000000) return -1;
    }
  }
  return tot;
}
