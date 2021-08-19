#include <iostream>
#include <vector>
#include <stdio.h>
#include <climits>

  
//g++ -std=c++11 .cpp -o      

using namespace std;


void explore(vector<vector<char>> &grid, int row, int col){

  bool rowInbound = row >= 0 && row < grid.size();
  bool colInbound = col >= 0 && col < grid[0].size();
  if( !rowInbound || !colInbound){
    return;
  }
  if(grid[row][col] == '-' || grid[row][col] == 'X'){
    return;
  }

  grid[row][col] = '-';
  explore(grid,row-1,col);
  explore(grid,row,col+1);
  explore(grid,row,col-1);
  explore(grid,row+1,col);

  return;
}



void surroundedRegions(vector<vector<char>>& grid){

  for(int i = 0; i<grid.size();i++){
    for (int j = 0; j<grid[0].size();j++){
      if((i == 0 || j == 0 || j== grid[0].size()-1 || i == grid.size()-1)){
        explore(grid,i,j);
      }
    }
  }

    for(int i = 0; i<grid.size();i++){
    for (int j = 0; j<grid[0].size();j++){
      if (grid[i][j] == '-'){
        grid[i][j] = 'O';
      }
      else if(grid[i][j] == 'O'){
        grid[i][j] = 'X';
      }
    }
  }
}



int main()
{

  
  vector<vector<char>> grid  = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};

  surroundedRegions(grid);

  for(int i = 0; i<grid.size();i++){
      for (int j = 0; j<grid[0].size();j++){
        cout<<grid[i][j]<<" ";
        }
      cout<<endl;
    }


}


