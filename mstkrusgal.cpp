#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int> > g[],int a,int b,int w){
  g[a].push_back(make_pair(b,w));
  g[b].push_back(make_pair(a,w));
}
int findparent(int *D,int a){
  if(D[a]=a)
    return a;
  D[a]=findparent(D,D[a]);
}
void unionD(int *D,int a,int b){
  int x=findparent(D,a);
  int y=findparent(D,b);
  if(x!=y)
    D[y]=x;
}
void krusgal(vector<pair<int,int> > G[],int *D,int n){
  vector<pair<int,pair<int,int> > > info;
  for(int i=0;i<n;i++){
    for(auto itr=G[i].begin();itr!=G[i].end();itr++){
    info.push_back(make_pair((*itr).second,make_pair(i,(*itr).first)));
    }
  }
  sort(info.begin(),info.end());
  for(int i=0;i<info.size();i+=2){
    int w=info[i].first;
    int src=info[i].second.first;
    int dest=info[i].second.second;
    if(findparent(D,src)!=findparent(D,dest)){
      unionD(D,src,dest);
      cout << src <<" --> "<<dest<<" == "<<w<<endl;
    }
  }
}
int main(){
  int n;
  n=10;
  vector<pair<int,int> > G[n];
   addEdge(G,0, 1,10);
    addEdge(G,0, 2,6);
    addEdge(G,0, 3,5);
    addEdge(G,1, 3,15);
    addEdge(G,2, 3,4);
    int D[n];
    for(int i=0;i<n;i++)  D[i]=i;
  krusgal(G,D,n);
  return 0;
}
