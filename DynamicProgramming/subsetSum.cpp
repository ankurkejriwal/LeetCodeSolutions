#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

bool subsetSum(vector<int> nums,int sum, int n){
    bool **dp = new bool*[n+1];
    for(int i = 0; i<n+1;i++){
        dp[i] = new bool[sum+1];
    }
    
    dp[0][0] = true;
    
    for(int i = 1; i<n+1; i++){
        dp[i][0] = true;
    }
    for(int i = 1; i<sum+1; i++){
        dp[0][i] = false;
    }
    
    for(int i = 1; i<n+1;i++){
        for(int j = 1; j<sum+1;j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
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
    vector<int> nums = {3,34,4,12,5,2};
    int sum = 9;
    int n = nums.size();
    bool result = subsetSum(nums,sum,n);
    cout<<subsetSum(nums,sum,n)<<endl;

    return 0;
}


