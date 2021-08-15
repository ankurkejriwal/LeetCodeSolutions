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

void DFSTraversal(unordered_map<string,vector<string>> graph, string src){
  stack<string> st;
  st.push(src);

  while(st.size() > 0){
    string top = st.top();
    st.pop();
    cout<<top<<" ";

    for (auto &neighbor : graph[top]){
      st.push(neighbor);
    }

  }
}

void DFS(unordered_map<string,vector<string>> graph, string src){
  cout<<src<<endl;
  for(auto & neighbors : graph[src]){
    DFS(graph,neighbors);
  }
}

void BFSTraversal(unordered_map<string,vector<string>> graph, string src){
  queue<string> q;
  q.push(src);

  while(q.size() > 0){
    string front = q.front();
    q.pop();
    cout<<front<<" ";

    for (auto &neighbor : graph[front]){
      q.push(neighbor);
    }

  }
}



int main()
{
  unordered_map<int,vector<int>> graph;
  vector<vector<int>> nums = {{1,3},{1,4},{2,3},{2,4},{4,3}};
  buildGraph(nums,graph);

  unordered_map<string,vector<string>> dfs;
  dfs["a"].push_back("c");
  dfs["a"].push_back("b");
  dfs["b"].push_back("d");
  dfs["c"].push_back("e");
  dfs["d"].push_back("f");


  BFSTraversal(dfs,"a");

}


