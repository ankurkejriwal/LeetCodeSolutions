#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

bool canPartitionKSubsets(vector<int>& nums, int k){
    int sum = 0;
    int n = nums.size();
    for(int i = 0; i<n;i++){
        sum+=nums[i];
    }
    if(sum%k != 0){
        return 0;
    }

    sum = sum/k;
    int **dp = new int*[n+1];
    for(int i = 0; i<n+1;i++){
        dp[i] = new int[sum+1];
    }
    
    dp[0][0] = 1;
    
    for(int i = 1; i<n+1; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i<sum+1; i++){
        dp[0][i] = 0;
    }
    
    for(int i = 1; i<n+1;i++){
        for(int j = 1; j<sum+1;j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            }
            else if(nums[i-1] > j){
                dp[i][j] = dp[i-1][j]; 
            }
        }
    }
    if(dp[n][sum] >= k) return true;
    return false;
}

int main()
{
    //vector<int> nums = {1,2,3,4};
    vector<int> nums = {4,3,2,3,5,2,1};
    
    int k = 4;
    cout<<canPartitionKSubsets(nums,k)<<endl;
    return 0;
}


