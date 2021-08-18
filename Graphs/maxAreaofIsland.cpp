#include <iostream>
#include <vector>
#include <stdio.h>
#include <climits>

  
//g++ -std=c++11 .cpp -o      

using namespace std;


int explore(vector<vector<int>> &grid, int row, int col,int **visited){
  //Check if row and column are inbound

  bool rowInbound = row >= 0 && row < grid.size();
  bool colInbound = col >= 0 && col < grid[0].size();
  if( !rowInbound || !colInbound){
    return 0;
  }
  if (grid[row][col] == 0){
    return 0;
  }
  if(visited[row][col] == 1){
    return 0;
  }
  visited[row][col] = 1;
  
  int size = 1;
  size+=explore(grid,row+1,col,visited);
  size+=explore(grid,row-1,col,visited);
  size+= explore(grid,row,col-1,visited);
  size+= explore(grid,row,col+1,visited);

  //cout<<size<<endl;
  return size;
}



int maxAreaOfIsland(vector<vector<int>>& grid){
  int count = INT_MIN;
  int **visited = new int*[grid.size()];
  for(int i = 0; i<grid.size();i++){
    visited[i] = new int[grid[0].size()];
  }

  for(int i = 0; i<grid.size();i++){
    for (int j = 0; j<grid[0].size();j++){
      int islandCount = explore(grid,i,j,visited);
      if(islandCount > 0){
        count = max(count,islandCount);
      }
    }
  }

  return count;
}



int main()
{

  
  vector<vector<int>> grid  = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};

  cout<<maxAreaOfIsland(grid)<<endl;

}


