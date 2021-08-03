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
int *dp;

int solve(int k){
  if(k<=0){
    return 0;
  }
  if(dp[k-1] != 0) return dp[k-1];
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
  return dp[k-1] = res;
}

  int minCost(vector<int> days, vector<int> cost){
  dp = new int[days[days.size()-1]];
  cst = cost;
  for(auto &num: days){
    st.insert(num);
  }
  return solve(days[days.size()-1]);
}

int main()
{
  // vector<int> days = {1,4,6,7,8,20};
  // vector<int> costs = {2,7,15};

  vector<int> days = {1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,21,24,25,27,28,29,30,31,34,37,38,39,41,43,44,45,47,48,49,54,57,60,62,63,66,69,70,72,74,76,78,80,81,82,83,84,85,88,89,91,93,94,97,99};
  vector<int> costs = {9,38,134};

  cout<<minCost(days,costs)<<endl;

}


