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


void buildGraphUndirected (vector<vector<string>>& edges,unordered_map<string,vector<string>> &graph){
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

int main()
{
  unordered_map<string,vector<string>> graph;
  vector<vector<string>> edges = {{"i","j"},{"k","i"},{"m","k"},{"k","l"},{"o","n"}};
  buildGraphUndirected(edges,graph);

  for (auto & node : graph["k"]){
    cout<<node<<endl;
  }

}


