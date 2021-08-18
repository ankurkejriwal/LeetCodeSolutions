#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>
  
//g++ -std=c++11 .cpp -o      

using namespace std;

typedef unordered_map<string,vector<string>> Graph;

int explore(vector<vector<string>> grid, int row, int col,unordered_set<string> &visited){
  //Check if row and column are inbound

  bool rowInbound = row >= 0 && row < grid.size();
  bool colInbound = col >= 0 && col < grid[0].size();
  if( !rowInbound || !colInbound){
    return 0;
  }
  if (grid[row][col] == "0"){
    return 0;
  }
  string visit = to_string(row)+","+to_string(col);
  if(visited.find(visit) != visited.end()){
    return 0;
  }
  visited.insert(visit);
  
  int size = 1;
  size+=explore(grid,row+1,col,visited);
  size+=explore(grid,row-1,col,visited);
  size+= explore(grid,row,col-1,visited);
  size+= explore(grid,row,col+1,visited);

  //cout<<size<<endl;
  return size;
}


int minIsland(vector<vector<string>> grid){
  int count = INT_MAX;
  unordered_set<string> visited;
  for(int i = 0; i<grid.size();i++){
    for (int j = 0; j<grid[0].size();j++){
      int islandCount = explore(grid,i,j,visited);
      if(islandCount > 0){
        count = min(count,islandCount);
      }
    }
  }

  return count;
}



int main()
{
  unordered_map<int,vector<int>> graph;
  vector<vector<int>> nums = {{1,3},{1,4},{2,3},{2,4},{4,3}};

  vector<vector<string>> grid2 = {{"1","1","0","0","0"},{"1","1","0","0","0"},{"0","0","1","0","0"},{"0","0","0","1","1"}};

  cout<<minIsland(grid2)<<endl;

}


