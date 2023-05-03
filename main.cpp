//
// File: Main.cpp
// Description: All permutations of names
// Created: Sun. March 26, 2023
// Author: Noah Sanderson
// mail: Noahs6423@student.vvc.edu
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// TODO: Write function to create and output all permutations of the list of names.
void PrintAllPermutations(const vector<string> &permList, const vector<string> &nameList) {

if (nameList.size() == 0) {
  for (unsigned int i = 0; i < permList.size(); ++i){
    if (i < permList.size() - 1){
      cout << permList.at(i) << ", ";
    }
    else {
      cout << permList.at(i) << endl;
    }
  }
}
else {
  vector<string> tmp1 = nameList;
  vector<string> tmp2 = permList;
  for(unsigned int i = 0; i < nameList.size(); ++i){
    string tmpStr = tmp1.at(i);
    tmp1.erase(tmp1.begin() + i);
    tmp2.push_back(tmpStr);
    PrintAllPermutations(tmp2 , tmp1);
    tmp1.insert(tmp1.begin() + i, tmpStr);
    tmp2.pop_back();
    }
  }
}
int main() {
   vector<string> nameList;
   vector<string> permList;
   string name;

   // TODO: Read a list of names into nameList; stop when -1 is read. Then call recursive function.
   cin >> name;
  while( name != "-1"){
    nameList.push_back(name);
    cin >> name;
  }
  PrintAllPermutations(permList, nameList);
   return 0;
}