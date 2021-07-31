#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;


// 4 Steps
// 1. Bounds of I and J: I = 0 ,  J = string.length()-1
// 2. Base condition: 
// 3. K Loop:
// 4. Function that transforms Temp ans -> final ans: 

//Break at the operatior

// ( 2 * 3 - 4 )* 5 
// Breaks into i->k-1 and k+1 -> j

// int solve(string str, int i, int j, vector<int> nums){
//   int i = 0;
//   int j = str.length()-1;}


unordered_map<string,vector<int>> mp;

vector<int> diffWaysBrackets(string str){
  vector<int> solution;
  for(int i = 0; i<str.size();i++){
    if(str[i] == '*' || str[i] == '+' || str[i] == '-'){
      vector<int> left = diffWaysBrackets(str.substr(0,i));
      vector<int> right = diffWaysBrackets(str.substr(i+1));
      for(auto &num1 : left){
        for(auto &num2 : right){
          if(str[i] == '*') solution.push_back(num1*num2);
          if(str[i] == '-') solution.push_back(num1-num2);
          if(str[i] == '+') solution.push_back(num1+num2);
        }
      }

    }
  }
  if (solution.empty()) solution.push_back(stoi(str));

    return solution; 
}

vector<int> diffWaysBracketsMemoized(string str){
  vector<int> solution;
  if(mp.count(str)){
    return mp[str];
  }
  for(int i = 0; i<str.size();i++){
    if(str[i] == '*' || str[i] == '+' || str[i] == '-'){
      vector<int> left = diffWaysBrackets(str.substr(0,i));
      vector<int> right = diffWaysBrackets(str.substr(i+1));
      for(auto &num1 : left){
        for(auto &num2 : right){
          if(str[i] == '*') solution.push_back(num1*num2);
          if(str[i] == '-') solution.push_back(num1-num2);
          if(str[i] == '+') solution.push_back(num1+num2);
        }
      }

    }
  }
  if (solution.empty()) solution.push_back(stoi(str));

    return mp[str] = solution; 
}



int main()
{
  string expression = "2*3-4*5";
  vector<int> result = diffWaysBrackets(expression);
  vector<int> result2 = diffWaysBracketsMemoized(expression);

  for(auto &num : result){
    cout<<num<<endl;
  }

   for(auto &num : result2){
    cout<<num<<endl;
  }

}


