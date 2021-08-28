#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
  
//g++ -std=c++11 .cpp -o      

using namespace std;

int explore(vector<vector<char>> &grid){
    int row = grid.size();
    int col = grid[0].size();
    int steps = 0;
    vector<vector<int>> visited(row,vector<int>(col,-1));

    queue<pair<int,int>> q;
    
    //Push all source nodes onto the queue
    for(int i = 0; i <row;i++){
        for (int j = 0; j<col;j++){
            if (grid[i][j] == 'S'){
                q.push({i,j});
                visited[i][j] = 1;
            }
        }
    }

    //Explore All valid neighbors of the current node
    const int dx[] = {1 , -1 , 0, 0};
    const int dy[] = {0 , 0 , 1, -1};

	while (q.size() > 0) {

		int n = q.size();
		for (int i = 0; i < n; i++) {
			pair<int,int> curr = q.front();
            q.pop();
			int x = curr.first;
			int y = curr.second;
			if (grid[x][y] == 'X') return steps;

			for (int j = 0; j<4; j++) {
				int newX = x + dx[j];
				int newY = y + dy[j];

                bool valid = (newX >= 0 && newX <grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] != 'D' && visited[newX][newY] != 1);
				if (valid) {
					q.push({newX, newY});
					visited[newX][newY] = 1;
				}
			}
		}
		steps++;
	}
    

    return -1;

}


int main(){

    vector<vector<char>> grid = 
    {{'S', 'O', 'O', 'S', 'S'},
    {'D', 'O', 'D', 'O', 'D'},
    {'O', 'O', 'O', 'O', 'X'},
    {'X', 'D', 'D', 'O', 'O'},
    {'X', 'D', 'D', 'D', 'O'}};

    cout<<explore(grid)<<endl;

}