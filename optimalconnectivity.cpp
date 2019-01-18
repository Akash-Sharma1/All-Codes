#include<bits/stdc++.h>
using namespace std;
void addedge(vector<pair<int,int> > &g[],int src,int dest,int w){
    g[src].push_back(make_pair(dest,w));
    g[dest].push_back(make_pair(src,w));
}
int lca(){
    
}
int bfs(vector<pair<int,int> > g[],int src,int dest,int n){
    queue<int> que;
    int visit[n]={0};
    que.push(src);
    visit[src]=1;
    int sum=0;
    pair<int,int > parent[n+1];
    while(!que.empty()){
        int x=que.front();
        que.pop();
        for(auto i=g[x].begin;i!=g[x].end();i++){
            if(!visit[(*i).first]){
                parent[(*i).first]=make_pair(x,(*i).second);
                que.push((*i).first);
                visit[(*i).first]=1;
            }
        }
    }
    int x=dest;
    while(x!=src){
        sum=parent[x].second;
        x=parent[x].first;
    }
    return sum;
}
int main(){
    int n;
    vector<pair<int,int> > g[n+1];
    for(int i=0;i<n;i++){
        int src,dest,wt;
        cin >> src >> dest>> wt;
        addedge(g,src,dest,wt);
    }
    int q;
    cin >> q;
    while(q--){
        int src,dest,wt;
        cin >> src >> dest>> wt;
        int old=bfs(g,src,dest,n+1);
        if(old > wt){cout << "YES\n";}
        else{cout << "NO\n";}
    }
}