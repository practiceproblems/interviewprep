#include <iostream>
#include <vector>
#include<string>
using namespace std;

/* Partitions array such that all elements >= pivot is on right side
 * and all elements less than pivot is on left side of array
 * The pivot values themselves need not be grouped together in center.
 */
size_t partition(vector<int> &vec, size_t begin, size_t end, int pivot){
  size_t low = begin, high = end;
  while (begin < end){
    while (begin<end && vec[begin] < pivot) ++begin;
    while (begin<end && vec[end] >= pivot) --end;
    if (begin < end){
      int t = vec[begin];
      vec[begin] = vec[end];
      vec[end] = t;
    }
  }
  vec[high] = vec[begin];
  vec[begin] = pivot;
  return begin;
}

void quick_sort(vector<int> &vec, size_t begin, size_t end) {
  size_t part = partition(vec, begin, end, vec[end]);
  if (part>0 && begin < part-1) quick_sort(vec, begin, part-1);
  if (part+1 < end ) quick_sort(vec, part+1, end);
}

void print(const vector<int> &vec, const string &info){
  cout<<info<<endl;
  for (vector<int>::const_iterator i = vec.begin(); i!= vec.end() ; ++i) {
    cout << *i << "\t";
  }
  cout << endl;
}

int main(){
    int arr[] = {-20,-30,6,9,3,0,-1,-10,5,-20};
  //   int arr[] = {1,2,3,4,5,6,7,8,9,10};
  //  int arr[] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
  vector<int> vec(arr,arr+10);
  print(vec,"Input");
  quick_sort(vec, 0, vec.size()-1);
  print(vec,"Ouput");
  return 0;
}
