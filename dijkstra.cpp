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
      if(!visit[itr->second] && dist[itr->second] > dist[p.second]+itr->first){
        dist[itr->second]=dist[p.second]+itr->first;
        pq.push(make_pair(dist[itr->second],itr->second));
        cout <<dist[itr->second] << " " << itr->second<<endl;
      }
    }
    cout<<endl;
  }
}
int main(){
  int n;
  n=10;
  vector<pair<int,int> > G[n];
  addEdge(G,0,2,1);
  dijkstra(G,n,0);
  return 0;
}
