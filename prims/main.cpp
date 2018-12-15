#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int> > g[],int a,int b,int w){
  g[a].push_back(make_pair(b,w));
  g[b].push_back(make_pair(a,w));
}
void prims(vector<pair<int,int> > G[],int n){
  priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > pq;
  int marked[n]={0};
  for(int i=0;i<n;i++){
    for(auto itr=G[i].begin();itr!=G[i].end();itr++){
      pq.push(make_pair(itr->second,itr->first));
      marked[i]=1;
    }
    if(marked[i]==1)
      break;
  }
  int noofedge=0;
  while(noofedge<n-1 || !pq.empty()){
    pair<int,int> info=pq.top();
    pq.pop();
    int w=info.first;
    int dest=info.second;
    if(!marked[dest]){
            marked[dest]=1;
      cout<<dest << " = "<<w <<endl;
      for(auto itr=G[dest].begin();itr!=G[dest].end();itr++){
        pq.push(make_pair(itr->second,itr->first));
      }
    }
  }

}
int main(){
  int n;
  n=10;
  vector<pair<int,int> > G[n];
  addEdge( G, 0, 1, 4);
   addEdge( G, 0, 7, 8);
   addEdge( G, 1, 2, 8);
   addEdge( G, 1, 7, 11);
   addEdge( G, 2, 3, 7);
   addEdge( G, 2, 8, 2);
   addEdge( G, 2, 5, 4);
   addEdge( G, 3, 4, 9);
   addEdge( G, 3, 5, 14);
   addEdge( G, 4, 5, 10);
   addEdge( G, 5, 6, 2);
   addEdge( G, 6, 7, 1);
   addEdge( G, 6, 8, 6);
   addEdge( G, 7, 8, 7);
  prims(G,n);
  return 0;
}
