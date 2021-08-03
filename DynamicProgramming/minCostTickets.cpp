#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <set>

//g++ -std=c++11 .cpp -o      

using namespace std;

vector<int> cst;
set<int> st;

int solve(int k){
  if(k<=0){
    return 0;
  }
  int res = INT_MAX;
  if(st.count(k)){
    int opt1 = solve(k-1)+cst[0];
    int opt7 = solve(k-7)+cst[1];
    int opt30 = solve(k-30)+cst[2];
    
    res = min(min(opt1,opt7),opt30);
  }
  else{
    res = solve(k-1);
  }
  return res;
}

  int minCost(vector<int> days, vector<int> cost){
  cst = cost;
  for(auto &num: days){
    st.insert(num);
  }
  return solve(days[days.size()-1]);
}

int main()
{
  vector<int> days = {1,4,6,7,8,20};
  vector<int> costs = {2,7,15};

  cout<<minCost(days,costs)<<endl;

}


