#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;


int maxCoinChange(vector<int> coins, int val){
    int **dp = new int*[coins.size()+1];
    
    for(int i = 0; i < coins.size()+1;i++){
        dp[i] = new int[val+1];
    }

    dp[0][0] = 1;
    for(int i = 1; i<coins.size()+1; i++){
        dp[i][0] = 1;
        for (int j = 1; j<val+1;j++){
            dp[0][j] = 0;
            if(coins[i-1] <= j){
                dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
            }
            else if (coins[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[coins.size()][val];
    
}

    int minCoinChange(vector<int> coins, int val){
    int **dp = new int*[coins.size()+1];
    
    for(int i = 0; i < coins.size()+1;i++){
        dp[i] = new int[val+1];
    }

    vector<int> result;

    dp[0][0] = INT_MAX -1;

    for(int j = 1; j<val+1; j++){
        if 
    }
    for(int i = 1; i<coins.size()+1; i++){
        dp[i][0] = 0;
        for (int j = 1; j<val+1;j++){
            dp[0][j] = INT_MAX-1;
            if(coins[i-1] <= j){
                dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
            }
            else if (coins[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            if(dp[i][val] > 0){
                result.push_back(dp[i][val]);
            }
        }
    }

    int mn = INT_MAX;

    for(auto &c : result){
        cout<<c<<",";
    }
    for(auto &c : result){
        mn =  min(c,mn);
    }
    return mn;
}

int main()
{
  vector<int> nums = {1,2,3};
  
  int sum = 5;

  cout<<minCoinChange(nums,sum)<<endl;


}


