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

bool explore(vector<vector<char>>& grid,int r, int c){
  bool rowInbound = r >= 0 && r<grid.size();
  bool colInbound = c >= 0 && c<grid[0].size();
  if(!rowInbound || !colInbound) return false;
  if (grid[r][c] ==  '.') return false;
  grid[r][c] = '.';

  explore(grid,r+1,c);
  explore(grid,r,c+1);

  return true;
}

int countBattleships(vector<vector<char>>& board){
    int count  = 0;

  for(int i = 0; i<board.size();i++){
    for(int j = 0; j<board[0].size();j++){
      if(explore(board,i,j)){
          count+=1;
      }
    }
  }
  return count;
}


int main()
{


  vector<vector<char>> grid = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
  
  cout<<countBattleships(grid)<<endl;

}


