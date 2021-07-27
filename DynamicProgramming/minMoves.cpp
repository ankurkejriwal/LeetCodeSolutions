#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

int minDistance(string word1, string word2) {
        int **dp = new int*[word1.length()+1];
        for(int i = 0; i<word1.length()+1;i++){
            dp[i] = new int[word2.length()+1];
        }
        
        dp[0][0] = 0;
        for(int i = 1; i<word1.length()+1;i++){
            dp[i][0] = 0;
            for(int j = 1; j<word2.length()+1;j++){
                dp[0][j] = 0;
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[word1.length()][word2.length()];
        
    }


    string longestCommonSubsequence(string text1, string text2) {
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

    }

int main()
{
  string s1 = "leetcode";

  string s2 = "etco";

  cout<<minDistance(s1,s2)<<endl;

}


