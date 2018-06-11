#include<iostream>
#include<vector>
#include<stack>

using namespace std;

#define MAX_N 5001

struct Node{
  vector<int> Adj;
};

Node graph[MAX_N];
bool mark[MAX_N];

inline void DFS(int start)
{
  stack<int> S;
  S.push(start);
  while(!S.empty()){
    int currnode=S.top();
    S.pop();
    mark[currnode]=true;
    cout<<"Traversing the node "<<currnode<<"\n";
    for(int i=0;i<graph[currnode].Adj.size();i++){
      if(!mark[graph[currnode].Adj[i]]){
        S.push(graph[currnode].Adj[i]);
        mark[graph[currnode].Adj[i]]=true;
      }
    }
  }
}

int main(){
  graph[0].Adj.push_back(1);
  graph[0].Adj.push_back(2);
  graph[2].Adj.push_back(3);
  graph[3].Adj.push_back(4);
  DFS(0);
  return 0;
}
