#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printGraph(vector<int> G[], int V)
{
        for (int i=0;i<10;i++){
                cout << "\n Adjacency list of vertex "<< i << "\n head ";
           for(int j=0;j<G[i].size();j++)
              cout <<" -> "<<G[i][j];
            cout << endl;
        }
}
void bfs(vector<int> G[],int n,int s){
  bool visited[n];
  for(int i=0;i<n;i++)
    visited[i]=false;
  queue<int> que;
  que.push(s);
  visisted[s]=true;
  while(!que.empty()){
    int temp=que.front();
    cout << temp <<" ";
    que.pop();
    for(int i=0;i<G[temp].size();i++){
      if(visited[G[temp][i]])
        continue;
        visited[G[temp][i]]=true;
      que.push(G[temp][i]);
    }
  }
}
void addEdge(vector<int> G[],int a,int b){
  G[a].push_back(b);
  G[b].push_back(a);
}
void dfsutil(vector<int> G[],int s){
  for(auto x: adj[s]){
    if(!visisted[*x]){
      visisted[*x]=true;
      dfsutil(G,*x);
    }
  }
  cout<< s <<" ";
}
void dfs(vector<int> G[],int n,int s){
  bool visited[n];
  for(int i=0;i<n;i++)
    visisted[i]=false;
  visited[s]=true;
    for(auto x: adj[s]){
      if(!visisted[*x]){
        visisted[*x]=true;
        dfsutil(G,*x);
      }
  }
  cout<<s;
}
int main(){
  int n=10;
  vector<int> G[10];
    addEdge(G, 0, 1);
    addEdge(G, 0, 4);
    addEdge(G, 1, 2);
    addEdge(G, 1, 3);
    addEdge(G, 1, 4);
    addEdge(G, 2, 3);
    addEdge(G, 3, 4);
    //printGraph(G,n);
    bfs(G,n,0);
    dfs(G,n,0);
  return 0;
}
