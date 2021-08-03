#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>

//g++ -std=c++11 .cpp -o      

using namespace std;

int minFallingPath(vector<vector<int>> matrix){
  int row = matrix.size(); 
  int col = matrix[0].size();
  if(row == 1 && col == 1){
    return matrix[0][0];
  }
  int **dp = new int*[row];
  for(int i = 0; i<row;i++){
    dp[i] = new int[col];
  }

  for(int i = 0; i<col; i++){
    dp[0][i] = matrix[0][i];
  }
  
  int mn = INT_MAX;

  for(int i = 1; i < row; i++){
    for(int j = 0; j < col; j++){
      if(j == 0){
        dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
      }
      else if(j== col-1){
        dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
      }
      else{
        dp[i][j] = matrix[i][j]+ min(min(dp[i-1][j],dp[i-1][j-1]),dp[i-1][j+1]);
      }
      if(i == row - 1){
        mn = min(mn,dp[row-1][j]);
      }
    }
  }
  return mn;
}




int main()
{
  vector<vector<int>> nums = {{2,1,3},{6,5,4},{7,8,9}};
  
  cout<<minFallingPath(nums)<<endl;

}


