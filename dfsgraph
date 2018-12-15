#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> g[],int a,int b){
  g[a].push_back(b);
  g[b].push_back(a);
}
void bfsq(vector<int> g[],int start,int n){
  queue<int> que;
  int visit[n]={0};
  que.push(start);
  visit[start]=1;
  while(!que.empty()){
    int temp=que.front();
    cout<<temp <<" ";
    que.pop();
    for(auto i=g[temp].begin();i!=g[temp].end();i++){
        if(!visit[*i]){
            visit[*i]=1;
            que.push(*i);
        }
    }
  }
}
int main(){
  int n;
  n=10;
  vector<int> G[n];
   addEdge(G,0, 1);
    addEdge(G,0, 2);
    addEdge(G,1, 2);
    addEdge(G,2, 0);
    addEdge(G,2, 3);
    addEdge(G,3, 3);
  bfsq(G,2,n);
  return 0;
}
