#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> g[],int a,int b){
  g[a].push_back(b);
  g[b].push_back(a);
}
void dfsq(vector<int> g[],int start,int n){
   stack<int> st;
   st.push(start);
   int visit[n]={0};
   visit[start]=1;
   while(!st.empty()){
     int temp=st.top();
     cout << temp<< " " ;
     st.pop();
     for(auto i=g[temp].begin();i!=g[temp].end();i++){
       if(!visit[*i]){
         visit[*i]=1;
         st.push(*i);
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
  dfsq(G,2,n);
  return 0;
}
