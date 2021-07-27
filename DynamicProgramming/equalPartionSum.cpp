#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

bool canPartition(vector<int> nums){
    int sum = 0;
    int n = nums.size();
    for(int i = 0; i<nums.size();i++){
        sum+= nums[i];
    }
    if(sum%2 != 0){
        return false;
    }
    sum = sum/2;
    bool **dp = new bool*[n+1];
    for(int i = 0; i<n+1;i++){
        dp[i] = new bool[sum+1];
    }

    dp[0][0] = true;
    for(int i = 1; i<n+1;i++){
        dp[i][0] = true;
    }
    for(int j = 0; j<sum+1;j++){
        dp[0][j] = false;
    }

    for(int i = 1; i<n+1;i++){
        for(int j = 1; j<sum+1;j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j-nums[i-1]]|| dp[i-1][j];
            }
            else if(nums[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    vector<int> nums = {1,5,11,5};
    int n = nums.size();
    cout<<canPartition(nums)<<endl;
    return 0;
}


