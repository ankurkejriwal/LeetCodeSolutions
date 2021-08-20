#include <iostream>
#include <vector>
#include <stdio.h>
#include <climits>

  
//g++ -std=c++11 .cpp -o      

using namespace std;

int ans = 0;

void explore(vector<vector<int>> &grid, int row, int col,int current,int  newColor){
  bool rowInbound = row >= 0 && row < grid.size();
  bool colInbound = col >= 0 && col < grid[0].size();
  if (!rowInbound || !colInbound) return;
  if (grid[row][col] != current) return;
  grid[row][col] = newColor;

  explore(grid,row+1,col,current,newColor);
  explore(grid,row-1,col,current,newColor);
  explore(grid,row,col+1,current,newColor);
  explore(grid,row,col-1,current,newColor);
  return;
}



vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
  if(image[sr][sc] == newColor) return image;
  explore(image,sr,sc,image[sr][sc],newColor);
  return image;
}



int main()
{

  
  vector<vector<int>> grid  = {{1,1,1},{1,1,0},{1,0,1}};
  
  floodFill(grid,1,1,2);

    for(int i = 0; i<grid.size();i++){
      for (int j = 0; j<grid[0].size();j++){
        cout<<grid[i][j]<<" ";
        }
      cout<<endl;
    }

}


