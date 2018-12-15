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
struct data{
    int a;
    int b;
};
void kruskgal(vector<pair<int,int> >*mst1,vector<pair<int,int> > G[10],int n,int *s){
    vector<pair<int,struct data*> > edgelist;
    for(int i=0;i<n;i++)
        for(auto x: G[i]){
                struct data*temp=new struct data;
                temp->a=i;
                temp->b=x.first;
            edgelist.push_back(make_pair(x.second,temp));
        }
        sort(edgelist.begin(),edgelist.end());
        for(int i=0;i<edgelist.size();i+=2){
            int w=edgelist[i].first;
            struct data* temp=edgelist[i].second;
            if(!cycle(s,temp->a,temp->b))
            {   cout << "edge between "<<temp->a<<"  and "<<temp->b<<endl;
                join(s,temp->a,temp->b);
                addEdge(mst1,temp->a,temp->b,w);
            }

        }
}
void printGraph(vector<pair<int,int> > G[], int V)
{
        for (int i=0;i<10;i++){
                cout << "\n Adjacency list of vertex "<< i << "\n head ";
           for(int j=0;j<G[i].size();j++)
              cout <<" -> "<<G[i][j].first;
            cout << endl;
        }
}
int main(){
  int n=10;
  vector<pair<int,int> >G[10];
  vector<pair<int,int> >mst1[10];
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

    kruskgal(mst1,G,n,st);
    //printGraph(mst1,n);
  return 0;
}
