#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

int canPartitionKSubsets(vector<int>& nums, int k){
    int sum = 0;
    int n = nums.size();
    for(int i = 0; i<nums.size();i++){
        sum+= nums[i];
    }
    if(sum%k != 0){
        return false;
    }
    sum = 6;
    int **dp = new int*[n+1];
    for(int i = 0; i<n+1;i++){
        dp[i] = new int[sum+1];
    }

    dp[0][0] = 1;
    for(int i = 1; i<n+1;i++){
        dp[i][0] = 1;
    }
    for(int j = 0; j<sum+1;j++){
        dp[0][j] = 0;
    }

    for(int i = 1; i<n+1;i++){
        for(int j = 1; j<sum+1;j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j-nums[i-1]]+dp[i-1][j];
            }
            else if(nums[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int subsetCount(vector<int>& nums, int x){
    int n = nums.size();
    int **dp = new int*[n+1];
    for(int i = 0; i<n+1;i++){
        dp[i] = new int[x+1];
    }

    dp[0][0] = 1;
    for(int i = 1; i<n+1;i++){
        dp[i][0] = 1;
    }
    for(int j = 0; j<x+1;j++){
        dp[0][j] = 0;
    }

    for(int i = 1; i<n+1;i++){
        for(int j = 1; j<x+1;j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j-nums[i-1]]+dp[i-1][j];
            }
            else if(nums[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][x];
}

int main()
{
    vector<int> nums = {3,3,3,3};
    int k = 6;
    //cout<<canPartitionKSubsets(nums,k)<<endl;
    cout<<subsetCount(nums,6)<<endl;
    return 0;
}


