#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int> > G[],int a,int b,int w){
  G[a].push_back(make_pair(b,w));
  G[b].push_back(make_pair(a,w));}
void dijkstra(vector<pair<int,int> > G[],int n,int src){
  int dist[n];
  int visit[n]={0};
  for(int i=0;i<n;i++){
    if(i!=src)
      dist[i]=INT_MAX;
    else
      dist[i]=0;}
  priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>> > pq;//distance from src, node's name
  pq.push(make_pair(0,src));
  while(!pq.empty()){
    pair<int,int> p =pq.top();
    pq.pop();
    if(visit[p.second])
      continue;
    visit[p.second]=1;
    for(auto itr=G[p.second].begin();itr!=G[p.second].end();itr++){
      if(!visit[itr->first] && dist[itr->first] > dist[p.second]+itr->second){
        dist[itr->first]=dist[p.second]+itr->second;
        pq.push(make_pair(dist[itr->first],itr->first));
      }
    }
  }
  for(int i=0;i<10;i++){cout << i << " --> " << dist[i]<<endl;}
}
int main(){
  int n;
  n=10;
  vector<pair<int,int> > G[n];
  addEdge(G,0,1,4);
  addEdge(G,1,2,8);
  addEdge(G,2,3,7);
  addEdge(G,3,4,9);
  addEdge(G,4,5,10);
  addEdge(G,5,6,2);
  addEdge(G,7,6,1);
  addEdge(G,7,0,8);
  addEdge(G,1,7,11);
  addEdge(G,2,8,2);
  addEdge(G,7,8,7);
  addEdge(G,8,6,6);
  addEdge(G,2,5,4);
  addEdge(G,3,5,14);
  dijkstra(G,n,0);
  return 0;
}
