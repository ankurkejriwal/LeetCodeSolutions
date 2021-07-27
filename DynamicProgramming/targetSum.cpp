#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <math.h>

using namespace std;

int findTargetSumWays(vector<int> & nums, int target){
    int **dp = new int*[nums.size()+1];
    int sum = 0;
    int count = 0;
 
    for(auto &n : nums){
        if (n == 0){
            count++;
        }
        sum+=n;
    }
    if(target > sum){
      return 0;
    }
    if((sum+target)%2 != 0){
      return 0;
    }
    sum = (target+sum)/2;

    for(int i =0 ; i<nums.size()+1;i++){
      dp[i] = new int[sum+1];
    }

    dp[0][0] = 1;

    for(int i = 1; i<nums.size()+1;i++){
      dp[i][0] = 1;
      for (int j = 1; j<sum+1;j++){
        dp[0][j] = 0;
        if(nums[i-1] > j || nums[i-1] == 0){
          dp[i][j] = dp[i-1][j];
        }
        else{
            dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
        }
      }
    }

    return pow(2,count)*dp[nums.size()][sum];

  }
int main()
{
  vector<int> nums = {1,1,1,1,1};
  
  int target = 3;

  cout<<findTargetSumWays(nums,target)<<endl;

}


