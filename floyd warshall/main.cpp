#include <iostream>
#define v 7
#define INF 9999
using namespace std;

void addedge(int adj[][v],int a,int b,int w){
    adj[a][b]=w;
    adj[b][a]=w;
}

void findallpath(int adj[][v]){
    int dist[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            dist[i][j]=adj[i][j];
        }
    }
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(adj[i][k]+adj[k][j]<adj[i][j])
                    adj[i][j]=adj[i][k]+adj[k][j];
            }
        }
    }
    for(int i=1;i<v;i++){
        for(int j=1;j<v;j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int adj[v][v];
     for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
           adj[i][j]=INF;
        }
    }
    addedge(adj,1,2,3);
    addedge(adj,2,3,4);
    addedge(adj,2,6,2);
    addedge(adj,6,4,6);
    addedge(adj,6,5,5);
    findallpath(adj);
    return 0;
}
