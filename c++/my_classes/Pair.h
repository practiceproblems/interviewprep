#define pragma once 
#include <ostream>
template <class T1, class T2>
struct Pair{

  Pair():first(T1()), second(T2()){} //default 
  Pair(T1 t1, T2 t2):first(t1), second(t2) {}

  //copy const and assignment
  Pair(const Pair<T1, T2> &other) {
    first = other.first;
    second = other.second;
  }
  void operator=(const Pair<T1, T2> &other){
    first =  other.first;
    second = other.second;
  }
  // operators...
  bool operator==(const Pair<T1, T2> &other){
    return (first == other.first && second == other.second);
  }
  void operator+=(const Pair<T1, T2> &other){
    first +=  other.first;
    second += other.second;
  }

  Pair<T1, T2> operator+(const Pair<T1, T2> &other){
    Pair<T1, T2> temp(*this); // copy
    temp += other;
    return temp;
  }
 
  void print(std::ostream &out){
    out << "[" << first<<","<<second<<"]\n";
  }

  T1 first;
  T2 second;
};
