#include <iostream>
#include <vector>
#include <stdio.h>
#include <climits>

  
//g++ -std=c++11 .cpp -o      

using namespace std;

bool ans = true;

void explore(vector<vector<int>> &grid,vector<vector<int>> &grid2,int row, int col,int **visited){
  //Check if row and column are inbound

  bool rowInbound = row >= 0 && row < grid2.size();
  bool colInbound = col >= 0 && col < grid2[0].size();
  if( !rowInbound || !colInbound){
    return;
  }
  if (grid2[row][col] == 0 ){
    return;
  }
  if(grid2[row][col] != grid[row][col]){
    ans =false;
  }

  grid2[row][col] = 0;

  explore(grid,grid2,row+1,col,visited);
  explore(grid,grid2,row-1,col,visited);
  explore(grid,grid2,row,col-1,visited);
  explore(grid,grid2,row,col+1,visited);
  return;
}



int countSubIslands(vector<vector<int>>& grid1,vector<vector<int>>& grid2){
  int count = 0;
  int **visited = new int*[grid1.size()];
  for(int i = 0; i<grid1.size();i++){
    visited[i] = new int[grid1[0].size()];
  }

  for(int i = 0; i<grid1.size();i++){
    for (int j = 0; j<grid1[0].size();j++){
      if(grid2[i][j]){
        explore(grid1,grid2,i,j,visited);
        if (ans) count++;
        ans = true;
      }
    }
  }
  return count;
}


int main()
{

  
  vector<vector<int>> grid1  = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
  vector<vector<int>> grid2  = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};

  cout<<countSubIslands(grid1,grid2)<<endl;

}


