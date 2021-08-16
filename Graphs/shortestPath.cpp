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

struct path {
  string node;
  int distance;
};

void buildGraphUndirected (vector<vector<string>> edges,unordered_map<string,vector<string>> &graph){
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

int shortestPath(unordered_map<string,vector<string>> graph,string src,string dest){
  unordered_set<string> visited;
  
  queue<path> q;
  path head;
  head.distance = 0;
  head.node = src;
  q.push(head);
  visited.insert(head.node); 

  int distance = 0;

  while(q.size() > 0){
    path top = q.front();
    q.pop();

    if (top.node == dest){
      return top.distance;
    } 

    for(auto & node: graph[top.node] ){
      if(visited.find(node) == visited.end()){
        path curr;
        curr.node = node;
        curr.distance = top.distance+1;
        q.push(curr);
        visited.insert(curr.node); 
      }
      
    }
  }

  return -1;
  
}


int main()
{
 
  vector<vector<string>> edges = {{"w","x"},{"x","y"},{"z","y"},{"z","v"},{"w","v"}} ;
  
  unordered_map<string,vector<string>> graph;

  buildGraphUndirected(edges,graph);

  cout<<shortestPath(graph,"w","z")<<endl;

}


