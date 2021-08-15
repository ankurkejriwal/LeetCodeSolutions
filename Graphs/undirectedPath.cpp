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

void buildGraphUndirected (vector<vector<string>>& edges,Graph &graph){
  for(auto&node : edges){
    string A = node[0];
    string B = node[1];

    if(graph.find(A) == graph.end()){
      graph[A] = vector<string>();
    }
    if(graph.find(B) == graph.end()){
      graph[B] = vector<string>();
    }
    graph[A].push_back(B);
    graph[B].push_back(A);
  }
}

bool hasPath(Graph graph, string src, string dest, unordered_set<string> &visited){
  if(visited.find(src) != visited.end()){
    return false;
  }
  visited.insert(src);
  if(src == dest){
    return true;
  }
  for(auto & neighbor : graph[src]){
    if(hasPath(graph,neighbor,dest,visited) == true){
      return true;
    }
  }
  return false;
}

int main()
{
  Graph graph;
  vector<vector<string>> edges = {{"i","j"},{"k","i"},{"m","k"},{"k","l"},{"o","n"}};
  buildGraphUndirected(edges,graph);
  unordered_set<string> visited;

  cout<<hasPath(graph,"j","m",visited)<<endl;

}


