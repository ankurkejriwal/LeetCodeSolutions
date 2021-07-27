#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

int cuttingRods(vector<int> &arr, vector<int> value, int n){
  int **dp = new int*[arr.size()+1];
  for(int i = 0; i<arr.size()+1;i++){
    dp[i] = new int[n+1];
  }
  dp[0][0] = 0;

  for(int i = 1; i<arr.size()+1;i++){
    dp[i][0] = 0;
    for(int j = 1; j<n+1;i++){
      if(arr[i-1] <= j){
        dp[i][j] = max(value[i-1]+dp[i][j-value[i-1]], dp[i-1][j]);
      }
      else if(arr[i-1] > j){
        dp[i][j] = dp[i-1][j];
      }
    }
  }
}

int main()
{
  vector<int> nums = {1,2,7};
  
  int sum = 0;
  for(int i = 0; i<nums.size();i++){
      sum+= nums[i];
  }

}


