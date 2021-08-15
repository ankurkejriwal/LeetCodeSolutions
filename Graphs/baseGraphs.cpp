#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <unordered_map>

//g++ -std=c++11 .cpp -o      

using namespace std;


void buildGraph (vector<vector<int>>& trust,unordered_map<int,vector<int>> &graph){
  for(auto&node : trust){
    int A = node[0];
    int B = node[1];
    if(graph.find(A) == graph.end()){
      graph[A] = vector<int>();
      }
    graph[A].push_back(B);
    }
}

int main()
{
  unordered_map<int,vector<int>> graph;
  vector<vector<int>> nums = {{1,3},{1,4},{2,3},{2,4},{4,3}};
  buildGraph(nums,graph);

  cout<<graph.size()<<endl;
  
}


