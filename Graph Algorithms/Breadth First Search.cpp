#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define MAX_N 5001

struct Node{
  vector<int> Adj;
};

Node graph[MAX_N];
bool mark[MAX_N];

inline void BFS(int start)
{
  queue<int> Q;
  Q.push(start);
  while(!Q.empty()){
    int currnode=Q.front();
    Q.pop();
    mark[currnode]=true;
    cout<<"Traversing the node "<<currnode<<"\n";
    for(int i=0;i<graph[currnode].Adj.size();i++){
      if(!mark[graph[currnode].Adj[i]]){
        Q.push(graph[currnode].Adj[i]);
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
  BFS(0);
  return 0;
}
