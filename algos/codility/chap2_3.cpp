vector<int> solution(int N, vector<int> &A) {
  // write your code in C++98
    
  vector<int> result;
  result.reserve(N);
  for (unsigned int i =0 ; i< N ;++i){
    result.push_back(0);
  }
  unsigned int max = 0;
  for (unsigned int i = 0 ; i< A.size() ; ++i){
    if (A[i] == N+1) { //set all to max
      for (unsigned int j =0 ; j< N ;++j){
	result[j] = max;
      }
    }
    else result[A[i]-1]++;
    if (result[A[i]-1] > max) max = result[A[i]-1];
  }
  return result;
}
