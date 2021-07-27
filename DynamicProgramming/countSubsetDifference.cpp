#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;


int countGivenDistance(vector<int> &nums , int diff){
  int **dp = new int*[nums.size()+1];
  int sum = 0;
  for(auto &c : nums){
    sum+=c;
  }
  sum = (diff+sum)/2;
  for(int i = 0 ; i<nums.size()+1;i++){
    dp[i] = new int[sum+1];
  }

  dp[0][0] = 1;

  for(int i = 1; i<nums.size()+1;i++){
        dp[i][0] = 1;
    for (int j = 1; j<sum+1;j++){
      dp[0][j] = 0;  
      if (nums[i-1] <= j){
        dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
      }
      else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }



  return dp[nums.size()][sum];

}
int main()
{
  vector<int> nums = {1,1,1,1,1};
  
  int diff = 3;


  cout<<countGivenDistance(nums,diff)<<endl;

  cout<<"Hello World"<<endl;


  return 0;
}


