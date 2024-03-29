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

typedef unordered_map<int,vector<int>> Graph;

bool explore(vector<vector<string>>& grid,int r, int c, unordered_set<string> &visited){
  bool rowInbound = r>= 0 && r<grid.size();
  bool colInbound = c>=0 && c<grid[0].size();
  if(!rowInbound || !colInbound) return false;

  if(grid[r][c] == "0") return false;

  string newVisit = to_string(r)+","+to_string(c);
  if(visited.find(newVisit) != visited.end()){
    return false;
  }
  visited.insert(newVisit);

  explore(grid,r-1,c,visited);
  explore(grid,r+1,c,visited);
  explore(grid,r,c-1,visited);
  explore(grid,r,c+1,visited);

  return true;
}

int islandcount(vector<vector<string>>& grid){
  unordered_set<string> visited;

  int count  = 0;

  for(int i = 0; i<grid.size();i++){
    for(int j = 0; j<grid[0].size();j++){
      if(explore(grid,i,j,visited) == true){
        count++;
      }
    }
  }
  return count;
}


int main()
{


  vector<vector<string>> grid = {{'1','1','1','1','0'},{"1","1","0","1","0"},{"1","1","0","0","0"},{"0","0","0","0","0"}};

  vector<vector<string>> grid2 = {{"1","1","0","0","0"},{"1","1","0","0","0"},{"0","0","1","0","0"},{"0","0","0","1","1"}};

  cout<<islandcount(grid)<<endl;
  cout<<islandcount(grid2)<<endl;


}


