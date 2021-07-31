#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

int static dp[1001][1001];



int solve (vector<int> sizes,int n, int k){


}



int matrixChainMult (vector<int> vals, int i, int j){
  int min = INT_MAX;
  if (i>=j){
    return 0;
  }
  for(int k = i; k<j-1;k++){
    int temp = solve(vals,i,k) + solve(vals,k+1,j) + vals[i-1]*vals[k]*vals[j];
    if (temp < min){
      min = temp;
    }
  }
  return min;
}

int matrixChainMultmemo (vector<int> vals, int i, int j){
  int mn = INT_MAX;
  if (i>=j){
    return 0;
  }
  if(dp[i][j] != -1){
    return dp[i][j];
  }
  for(int k = i; k<j-1;k++){
    int temp = solve(vals,i,k) + solve(vals,k+1,j) + vals[i-1]*vals[k]*vals[j];
    if (temp < mn){
      mn = temp;
    }
  }
  return dp[i][j] = mn;
}


int main()
{
  vector<int> nums = {1,2,7};
  memset(dp,-1,sizeof(dp));

}


