#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>
#include<unordered_map>

//g++ -std=c++11 .cpp -o      

using namespace std;

unordered_map<string,int> mp;

bool isScramble(string a, string b){
  if(a.compare(b) == 0){
    return true;
  }
  if (a.length()<=1){
    return false;
  }
  int n = a.length();
  bool flag = false;
  string key = a+" "+b;
  if(mp.count(key)){
      return mp[key];
    }
  for(int i = 1; i<a.size(); i++){
    if(isScramble(a.substr(0,i),b.substr(0,i)) && isScramble(a.substr(i,a.length()-i),b.substr(i,b.length()-i))){
      flag = true;
      break;
    }
    if (isScramble(a.substr(0,i),b.substr(b.length()-i,i)) && isScramble(a.substr(i,a.length()-i),b.substr(0,b.length()-i))){
      flag = true;
      break;
    }
  }

  return mp[key] = flag;

}

int main()
{
  string a = "abcde";
  string b = "caebd";

  string c = "abcdefghijklmnopq";
  string d = "efghijklmnopqcadb";

  cout<<isScramble(a, b)<<endl;
  cout<<isScramble(c,d)<<endl;

}


