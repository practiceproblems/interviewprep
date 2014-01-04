#define pragma once
#include <ostream>

template <class T>
class MyVector{
 public:
  MyVector():_arr(NULL), _size(0) {};
  MyVector(size_t size){
    _size = size;
    _arr = new T[size];
  }
  MyVector(const MyVector &other) {
    copy(other);
  }

  ~MyVector() { delete [] _arr;}

  bool operator==(const MyVector &other) {
    if (other._size != _size) return false;
    for (uint i =0; i< other._size ;++i){
      if (_arr[i] != other._arr[i]) return false;
    }
    return true;
  }
  
  MyVector& operator=(const MyVector &other){
    if (this != &other){
      delete[] _arr;
      copy(other);
    }
    return *this;
  }

  MyVector& operator+(const MyVector &other) {
    MyVector temp(_size + other._size);
    for (uint i =0; i< _size ;++i){
      temp[i] = _arr[i];
    }
    for (uint i =_size; i< other._size ;++i){
      temp[i] = other._arr[i-_size];
    }
    return temp;
  }

  std::ostream& operator<<(std::ostream &out){
    out << "[";
    char delim =' ';
    for (size_t i=0; i < _size; ++i){
      out << delim << _arr[i];
      delim = ',';
    }
    out << "]\n";
    return out;
  }

  T& operator[](const size_t index){
    return _arr[index];
  }

 private:
  void copy(const MyVector &other){
    _arr = new T[other._size];
    _size = other._size;
    for (uint i =0; i< other._size ;++i){
      _arr[i] = other._arr[i];
    }
  }

  T *_arr;
  size_t _size;

};
