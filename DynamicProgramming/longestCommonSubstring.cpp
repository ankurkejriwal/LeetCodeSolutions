#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;


int longestCommonSubsequence(string str1, string str2, int n, int k){
    if(n == 0 || k == 0){
        return 0;
    }
    if (str1[n-1] == str2[k-1]){
        return 1+longestCommonSubstring(str1,str2,n-1,k-1);
    }
    else{
        return max(longestCommonSubstring(str1,str2,n-1,k), longestCommonSubstring(str1,str2,n,k-1));
    }
}

int memoized(string str1, string str2, int n, int k){
    int **dp = new int*[n+1];
    for(int i = 0; i<n+1;i++){
        dp[i] = new int[k+1];
    }

    for(int i = 1; i<n+1; i++){
        dp[i][0] = 0;
        for (int j = 1; j < k+1; j++){
            dp[0][j] = 0;
            if(str1[i] == str2[j]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][k];

}

int main()
{
  string s1 = "ABCDGH";
  string s2 = "abedfhr";

  cout<<lcs(s1,s2,s1.size(),s2.size())<<endl;

 
}


