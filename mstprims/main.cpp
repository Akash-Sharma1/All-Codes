#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int> > G[],int a,int b,int w){
  G[a].push_back(make_pair(b,w));
  G[b].push_back(make_pair(a,w));
}
int findparent(int *s,int a){
    if(s[a]==a)
        return a;
      s[a]=findparent(s,s[a]);
}
void join(int *s,int a,int b){
    s[b]=a;
}
bool cycle(int *s,int a,int b){
    if(findparent(s,a)==findparent(s,b))
        return true;
    return false;
}

void prims(vector<pair<int,int> > G[10],int n,int *s,int start){
    priority_queue<pair<int,pair<int,int> > > pq;
    for(auto x: G[start])
    {
        pq.push(make_pair(x.second,make_pair(start,x.first)) );

    }
    int edges=0;
    while(edges<n-1){
        int a=pq.top().second.first;
        int b=pq.top().second.second;
        pq.pop();
        if(!cycle(s,a,b)){
            join(s,a,b);
            cout << a <<" --> "<< b<<endl;
            for(auto x: G[b])
                 pq.push(make_pair(x.second,make_pair(b,x.first)) );
        }
    }
}

int main(){
  int n=10;
  vector<pair<int,int> >G[10];
    addEdge(G,0, 1,10);
    addEdge(G,0, 2,6);
    addEdge(G,0, 3,5);
    addEdge(G,1, 3,15);
    addEdge(G,2, 3,4);
    //printGraph(G,n);
    int st[n];
    for(int i=0;i<n;i++){
        st[i]=i;
    }

    prims(G,n,st,0);
    return 0;
}
