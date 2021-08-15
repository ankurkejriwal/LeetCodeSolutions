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

bool hasPathDFS(unordered_map<string,vector<string>> mp, string src,string dst){
  if (src == dst){
    return true;
  }

  for(auto & node : mp[src]){
    if(hasPathDFS(mp,node,dst) == true){
      return true;
    }
  }
  return false;
}

bool hasPathBFS(unordered_map<string,vector<string>> mp, string src, string dst){
  queue<string> q;
  q.push(src);
  while(q.size() > 0){
    
    string curr = q.front();
    q.pop();

    if(curr == dst){
      return true;
    }

    for(auto & node: mp[curr]){
      q.push(node);
    }
  }

  return false;
}


int main()
{
  unordered_map<int,vector<int>> graph;
  vector<vector<int>> nums = {{1,3},{1,4},{2,3},{2,4},{4,3}};

  unordered_map<string,vector<string>> dfs;
  dfs["f"].push_back("g");
  dfs["f"].push_back("i");
  dfs["g"].push_back("h");
  dfs["h"].push_back(" ");
  dfs["i"].push_back("g");
  dfs["g"].push_back("k");
  dfs["j"].push_back("i");
  dfs["k"].push_back(" ");



  cout<<hasPathDFS(dfs,"f","k")<<endl; //1
  cout<<hasPathBFS(dfs,"f","k")<<endl; // 1


}


