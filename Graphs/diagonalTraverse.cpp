#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>


//g++ -std=c++11 .cpp -o      

using namespace std;



vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
  queue<pair<int,int>> q;
  q.push({0,0});

  vector<int> ans = {};

  vector<vector<int>> visited  = nums;

  while(q.size() > 0){
    int row = q.front().first;
    int col = q.front().second;
    q.pop();
    if(visited[row][col] != 0){
      ans.push_back(nums[row][col]);
      visited[row][col] = 0;
    }
    if(row + 1 < nums.size() && col < nums[row+1].size()){
      //nums[row+1][col] = -1;
      q.push({row+1,col});
    }
    if(col + 1 < nums[row].size() && row < nums.size()){
      q.push({row,col+1});
    }
  }
  return ans;
}


int main()
{


 vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};

 vector<int> ans = findDiagonalOrder(nums);

 for(auto & num : ans){
   cout<<num<<" ";
 }



}


