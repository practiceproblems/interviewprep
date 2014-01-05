#include<iostream>
#include<vector>
using namespace std;
// Some failed tests. Score 77/100
/*
extreme_small 
all max_counter operations0.020 s.WRONG ANSWER 
got [337, 337, 337, 337,.. expected [0, 0, 0, 0, 0]
single 
only one counter0.020 s.OK
small_random1 
small random test, 6 max_counter operations0.020 s.WRONG ANSWER 
got [0, 0, 0, 2, 3, 2, 2.. expected [9, 9, 9, 9, 9, 9, 9.
 */

vector<int> solution(int N, vector<int> &A) {
  // write your code in C++98
    
  vector<int> result;
  result.reserve(N);
  for (unsigned int i =0 ; i< N ;++i){
    result.push_back(0);
  }
  unsigned int max = 0;
  long int last_max =-1;
  for (unsigned int i = 0 ; i< A.size() ; ++i){
    if (A[i] == N+1) { //set all to max
      // dont set max everytime, just remember the last set one.
      /*
      for (unsigned int j =0 ; j< N ;++j){
	result[j] = max;
	}*/
      last_max = max;
    }
    else {
      if (last_max != -1 && result[A[i]-1] < last_max){
	result[A[i]-1] = last_max + 1;
      }
      else{
	result[A[i]-1]++;
      }
    }
    if (result[A[i]-1] > max) max = result[A[i]-1];
  }

  // some of the ones may not have been set since the last max operation.
  for (unsigned int i =0 ; i< N ;++i){
    if (last_max != -1 && result[i] < last_max){
      result[i] = last_max;
    }
  }
  return result;
}

int main(){
  vector<int> sol, inp;
  inp.push_back(4);
  inp.push_back(4);
  inp.push_back(4);
  inp.push_back(4);

  sol = solution(3, inp);
  for (int i=0 ;i<3; ++i )
    cout <<sol[i] <<endl;
  return 0;
}
