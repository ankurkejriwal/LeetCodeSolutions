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

bool explore(Graph &graph,int src,unordered_set<int> &visited){
  if(visited.find(src) != visited.end()){
    return false;
  }
  visited.insert(src);
  for(auto & node : graph[src]){
    explore(graph,node,visited);
  }
  return true;
}

int connectedComponentCount(Graph graph){
  unordered_set<int> visited;
  int count = 0;
  for (auto& node : graph){
    if(explore(graph,node.first,visited) == true){
      count++;
    }
  }
  return count;
}


int main()
{
  Graph graph;

  graph[0] = {8,1,5};
  graph[1] = {0};
  graph[5] = {0,8};
  graph[8] = {0,5};
  graph[2] = {3,4};
  graph[3] = {2,4};
  graph[4] = {3,2};
  
  cout<<connectedComponentCount(graph)<<endl;


}


