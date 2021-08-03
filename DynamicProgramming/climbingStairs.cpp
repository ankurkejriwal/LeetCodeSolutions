#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>

//g++ -std=c++11 .cpp -o      

using namespace std;

int climbStairs(int n) {
        int* dp = new int[max(n+1,3)];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i<=n; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
}

int main()
{
    cout<<climbStairs(7)<<endl;
}


