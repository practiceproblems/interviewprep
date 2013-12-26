#include <iostream>
using namespace std;


// O(n^2)
void bubble_sort(int arr[], size_t len){

  for (size_t i=0 ;i<len; ++i){
    int min_idx=i;
    for (size_t j=i+1 ;j<len; ++j) {
      if (arr[j] < arr[min_idx]){
        min_idx = j;
      }
    }
    int t = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = t;   
   }
   // print the contents.
   for (size_t i=0 ;i<len; ++i){
    cout <<arr[i] << "\t";
   }
   cout <<endl;
}


int main(){
  int arr[] = {1,2,4,9,3,2,0,10,7,-2};
  bubble_sort(arr, 10);
  int arr1[] = {1,1,1,1,1};
  bubble_sort(arr1, 5);
  int arr2[] = {1};
  bubble_sort(arr2, 1);
  int arr3[] = {};
  bubble_sort(arr3, 0);

}
