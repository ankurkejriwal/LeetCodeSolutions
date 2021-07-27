#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string shortestCommonSupersequence(string text1, string text2) {
        int **dp = new int*[text1.length()+1];
        for(int i = 0; i<text1.length()+1;i++){
            dp[i] = new int[text2.length()+1];
        }
        int n = text1.length();
        int k = text2.length();
        
        dp[0][0] = 0;
        for(int i = 1; i<n+1;i++){
            dp[i][0] = 0;
            for(int j = 1; j<k+1;j++){
                dp[0][j] = 0;
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        cout<<dp[text1.size()][text2.size()]<<endl;

    string res = "";

    int i = text1.length();
    int j = text2.length();
    while(j > 0 && i > 0){
        if (text1[i-1] == text2[j-1]){
            res.push_back(text1[i-1]);
            i--;
            j--;
        }
        else{
            if (dp[i-1][j] > dp[i][j-1]){
                res.push_back(text1[i-1]);
            i--;
            }
            else{
            res.push_back(text2[j-1]);
            j--;
            }
        }
    }

    while(i>0){
        res.push_back(text1[i-1]);
        i--;
    }
    while(j>0){
        res.push_back(text2[j-1]);
        j--;
    }
    return res;
}

int main()
{
  string s1 = "abac";
  string s2 = "cab";
  string res = shortestCommonSupersequence(s1, s2);

  
  //reverse(res.begin(),res.end());
  cout<<res<<endl;


}


