/*
http://www.careercup.com/question?id=5765850736885760
Mapping 
'1' = 'A','B','C' 
'2' = 'D','E','F' 
... 
'9' = 

input: 112 
output :ouput = [AAD, BBD, CCD, AAE, AAF, BBE, BBF, CCE, CCF]
 */

// TO LEARN:
// returning vector... causing to copy. see how to use pointers or reference  here.

#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

// init some data structures used later.
// 1. positionsMap:
// construct a map (key is int, value is a vector of positions where that number occurs)
// eg:112 , for key=1, val=(0,1) and key=2, val (2).
//
// 2. mappings:
// construct a map to find the mappings. eg 1=>A,B,C 2=>D,E,F ... 9=>Y,Z 
// we only add keys which are present in input. 
void init(const string& input, map<char, vector<size_t> > &positionsMap, map<char, vector<char> > &mappings){
  positionsMap.clear();
  mappings.clear();

  for (unsigned i = 0; i<input.size() ;++i){
    if (input[i] <'1' || input[i] >'9'){
      throw runtime_error("Invalid input");
    } 
    if (positionsMap.find(input[i]) != positionsMap.end()){ // already in map add to exisiting vector
      positionsMap[input[i]].push_back(i);
    }
    else{
      vector<size_t> vec;
      vec.push_back(i);
      positionsMap[input[i]] = vec;
    }

    if (mappings.find(input[i]) == mappings.end() ){
      vector<char> vec;
      unsigned int num = static_cast<int>(input[i]) - '0';
      char start = 'A';
      vec.push_back(start + 3*(num-1));
      vec.push_back(start + 3*(num-1) +1);
      if (num!=9) vec.push_back(start + 3*(num-1)+ 2); // when num=9, we have only 2 values: Y and Z.
      mappings[input[i]] = vec;
    }
  }
  
  // print the ds we have just built...for debugging.
  cout <<"Mappings...\n";
  map<char,vector<char> >::const_iterator mappings_iter = mappings.begin();  
  while (mappings_iter != mappings.end()) {
    cout << mappings_iter->first << "=>";
    vector<char> val = mappings_iter->second;
    for (vector<char>::const_iterator i = val.begin(); i!= val.end() ; ++i){
      cout << *i <<"\t";
    }
    cout << endl;
    ++mappings_iter;
  }
  cout <<"Positions map...\n";
  map<char, vector<size_t> >:: const_iterator positions_iter = positionsMap.begin();
  while (positions_iter != positionsMap.end()) {
    cout << positions_iter->first << "=>";
    vector<size_t> val = positions_iter->second;
    for (vector<size_t>::const_iterator i = val.begin(); i!= val.end() ; ++i){
      cout << *i <<"\t";
    }
    cout << endl;
    ++positions_iter;
  }

}

// for all the positions in the string fill it with char c.
void fillStr(string &str, vector<size_t> &positions, char c){
  unsigned len = str.size();
  for (vector<size_t>::const_iterator i = positions.begin() ; i != positions.end() ; ++i){
    if (*i >=len){
      cout <<len <<"<=" <<*i <<endl;
      throw runtime_error("Invalid position");
    }
    str[*i] = c;
  }
}

void permute(const string& input, 
             map<char, vector<size_t> > &positionsMap, 
             map<char, vector<char> > &mappings,
             string& out,
             map<char,vector<char> >::iterator iter){
        
  if (iter == mappings.end()){
    // we have filled everything, print the output.
    cout << out << endl;
    return;
  }
  char key = iter->first;
  vector<char> val = iter->second;
  map<char,vector<char> >::iterator  next = std::next(iter,1);
  for (vector<char>::const_iterator i = val.begin(); i!= val.end() ; ++i){
    fillStr(out,positionsMap[key] ,*i);
    permute(input, positionsMap, mappings, out, next); // <--- main recursive call.
  }
}

int main(){
  map<char, vector<size_t> > positionsMap;
  map<char, vector<char> > mappings;
  string input = "112";
  string out = input;
  init(input, positionsMap, mappings);
  cout <<"\n\nOutput:\n";
  permute(input, positionsMap, mappings, out, mappings.begin());
  return 0;
}
