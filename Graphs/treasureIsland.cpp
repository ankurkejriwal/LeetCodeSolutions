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
    
    int steps = 0;
    queue<pair<int,int>> q;
    q.push({0,0});
    vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
    visited[0][0] = 1;

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

	return 0;

}



int main(){
    vector<vector<char>> grid = 
    {{'O', 'O', 'O', 'O'},
    {'D', 'O', 'D', 'O'},
    {'O', 'O', 'O', 'O'},
    {'X', 'D', 'D', 'O'}};

    cout<<explore(grid)<<endl;

}