#include <iostream>
#include <vector>
#include <stdio.h>
#include <climits>

  
//g++ -std=c++11 .cpp -o      

using namespace std;

int ans = 0;

void explore(vector<vector<int>> &grid, int row, int col){
  if(row >= grid.size() || row < 0 || col >= grid[0].size()|| col < 0 || grid[row][col] == 0){
    ans+=1;
    return;
  } 
  if(grid[row][col] == -1) return;
  grid[row][col] = -1;
  
  explore(grid,row+1,col);
  explore(grid,row-1,col);
  explore(grid,row,col-1);
  explore (grid,row, col + 1);

  return;
}



int islandPerimeter(vector<vector<int>>& grid){
  
  for(int i = 0; i<grid.size();i++){
    for (int j = 0; j<grid[0].size();j++){
      if(grid[i][j]){
        explore(grid,i,j);
      }
    }
  }

  return ans;

}



int main()
{

  
  vector<vector<int>> grid  = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};

  cout<<islandPerimeter(grid)<<endl;

}


