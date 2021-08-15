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

bool hasPath(unordered_map<string,vector<string>> mp, string src,string dst){
  if (src == dst){
    return true;
  }

  for(auto & node : mp[src]){
    if(hasPath(mp,node,dst) == true){
      return true;
    }
  }
  return false;
}


int main()
{
  unordered_map<int,vector<int>> graph;
  vector<vector<int>> nums = {{1,3},{1,4},{2,3},{2,4},{4,3}};
  buildGraph(nums,graph);

  unordered_map<string,vector<string>> dfs;
  dfs["f"].push_back("g");
  dfs["f"].push_back("i");
  dfs["g"].push_back("h");
  dfs["h"].push_back(" ");
  dfs["i"].push_back("g");
  dfs["g"].push_back("k");
  dfs["j"].push_back("i");
  dfs["k"].push_back(" ");



  cout<<hasPath(dfs,"f","k")<<endl;

}


