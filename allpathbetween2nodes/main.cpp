#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addedge(vector<pair<int,int> > adj[],int a,int b,int w){
    adj[a].push_back(make_pair(b,w));
   // adj[b].push_back(make_pair(a,w));
}
void findpath(vector<pair<int,int> > adj[],int curr,int dest,vector<int> &ap,int *visited){
    ap.push_back(curr);
    if(curr==dest){
      for(auto itr=ap.begin();itr!=ap.end();itr++){cout << *itr <<" ";}
      cout <<endl;
      return;
    }
    for(int i=0;i<adj[curr].size();i++){
        if(visited[adj[curr][i].first]!=1){
        visited[adj[curr][i].first]=1;
        findpath(adj,adj[curr][i].first,dest,ap,visited);
        ap.pop_back();
        visited[adj[curr][i].first]=0;
        }
    }
}

void findallpath(vector<pair<int,int> > adj[],int src,int dest){
    vector<int> ap;
    int visited[4]={0};
    visited[src]=1;
    ap.push_back(src);
    for(int i=0;i<adj[src].size();i++){
        visited[adj[src][i].first]=1;
        findpath(adj,adj[src][i].first,dest,ap,visited);
        ap.pop_back();
    }
}
int main()
{
    vector<pair<int,int> > adj[4];
    addedge(adj,0,1,1);
    addedge(adj,0,2,1);
    addedge(adj,0,3,1);
    addedge(adj,2,0,1);
    addedge(adj,2,1,1);
    addedge(adj,1,3,1);
    findallpath(adj,2,3);
    return 0;
}
