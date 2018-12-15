#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void addedge1(vector<int> g[10],int a,int b){
  g[a].push_back(b);
  g[b].push_back(a);
}
int main(){
  int n;
  n=10;
  vector<int> G[n];
  addedge1(G,1,2);
  for(int i=0;i<n;i++){
        cout << i << " --> ";
    for(int j=0;j<G[i].size();j++){
        cout << j <<" --> ";
    }
    cout << endl;
  }
  return 0;
}
