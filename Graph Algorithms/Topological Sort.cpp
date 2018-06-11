#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define MAX_N 5001

struct Node{
  vector<int> Adj;
};

int n;
Node Graph[MAX_N];
int indegree[MAX_N];

inline int TopologicalSort()
{
  queue<int> S;
  for(int i=0;i<n;i++)
  {
    if(indegree[i]==0){
      S.push(i);
    }
  }
  int counter=0;
  while(!S.empty())
  {
    int currnode=S.front();
    S.pop();
    cout<<"\n"<<currnode;
    counter++;
    for(int i=0;i<Graph[currnode].Adj.size();i++)
    {
      if(--indegree[Graph[currnode].Adj[i]]==0){
        S.push(Graph[currnode].Adj[i]);
      }
    }
  }
  if(counter<n) return -1;
  return 0;
}

int main(){
  n=8;
  Graph[7].Adj.push_back(0);
  Graph[7].Adj.push_back(5);
  Graph[7].Adj.push_back(6);
  Graph[4].Adj.push_back(5);
  Graph[3].Adj.push_back(7);
  Graph[3].Adj.push_back(4);
  Graph[2].Adj.push_back(7);
  Graph[1].Adj.push_back(4);
  Graph[1].Adj.push_back(6);

  indegree[0]=1;
  indegree[1]=0;
  indegree[2]=0;
  indegree[3]=0;
  indegree[4]=2;
  indegree[5]=2;
  indegree[6]=2;
  indegree[7]=2;

  TopologicalSort();
  return 0;
}
