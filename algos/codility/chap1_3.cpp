

// Tape equilibrium - 100%



// you can also use includes, for example:
// #include <algorithm>
#include <climits>
int solution(vector<int> &A) {
  // write your code in C++98
  vector<long int> running_sum;
  running_sum.reserve(A.size());
  long int sum_so_far = 0;
  for (vector<int>::const_iterator i = A.begin(); i != A.end() ; ++i) {
    sum_so_far += *i;
    running_sum.push_back(sum_so_far);
  }
  unsigned long int min_diff = ULONG_MAX;
    
  for (size_t p = 1; p < A.size() ; ++p) {
    unsigned long diff = abs  (running_sum[p-1]  - (running_sum[running_sum.size()-1] - running_sum[p-1] ));
    if (diff < min_diff){
      min_diff = diff;
    }
  }
  return min_diff;
}

