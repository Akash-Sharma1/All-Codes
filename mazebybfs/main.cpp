#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
using namespace std;
void gotoxy( int column, int line ){
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }
  void printcube(int x,int y){
    for(int i=x;i<x+4;i++)
        for(int j=y;j<y+2;j++){
            gotoxy(i,j);
            cout<<"#";
        }
  }
  void printuser(int x,int y){
    for(int i=x;i<x+4;i++)
        for(int j=y;j<y+2;j++){
            gotoxy(i,j);
            cout<<"O";
        }
  }
  void removebackstep(int x,int y){
    for(int i=x;i<x+4;i++)
        for(int j=y;j<y+2;j++){
            gotoxy(i,j);
            cout<<" ";
        }
  }
void makemaze(int adj[10][10]){
    int x=5,y=40;
    for(int i=0;i<10;i++){
        y=40;
       for(int j=0;j<10;j++){
            if(adj[i][j]==1){
                printcube(y,x);
            }
        y+=4;
       }
       x+=2;
    }

}
void findpathfrom(int sx,int sy,int dx,int dy,int adj[10][10]){
    pair<int,int> visit[10][10];
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            visit[i][j]=make_pair(-1,-1);

    queue<pair<int,int> > que;
    que.push(make_pair(sx,sy));
    visit[sx][sy]=make_pair(sx,sy);//source vertex
    while(!que.empty()){
        int tempx=que.front().first;
        int tempy=que.front().second;
        if(tempx==dx && tempy==dy)
            break;
        que.pop();
        if((tempx-1)>=0 && adj[tempx-1][tempy]==0 && visit[tempx-1][tempy].first==-1){
            que.push(make_pair(tempx-1,tempy));
            visit[tempx-1][tempy]=make_pair(tempx,tempy);
        }
        if((tempx+1)<10 && adj[tempx+1][tempy]==0 && visit[tempx+1][tempy].first==-1){
            que.push(make_pair(tempx+1,tempy));
            visit[tempx+1][tempy]=make_pair(tempx,tempy);
        }
        if((tempy-1)>=0 && adj[tempx][tempy-1]==0 && visit[tempx][tempy-1].first==-1){
            que.push(make_pair(tempx,tempy-1));
            visit[tempx][tempy-1]=make_pair(tempx,tempy);
        }
        if((tempy+1)<10 && adj[tempx][tempy+1]==0 && visit[tempx][tempy+1].first==-1){
            que.push(make_pair(tempx,tempy+1));
            visit[tempx][tempy+1]=make_pair(tempx,tempy);
        }
    }

    while(dx!=sx || sy!=dy){
        int tempx=visit[dx][dy].first;
        int tempy=visit[dx][dy].second;
        cout << tempx <<" "<< tempy <<endl;
        dx=tempx;
        dy=tempy;
    }
}

int main()
{
   // int sx,sy,dx,dy;

   int adjmat[10][10]={{1,0,1,1,1,1,1,1,1,1},
                     {1,0,0,0,1,1,1,1,1,1},
                     {1,0,1,1,0,1,1,1,1,1},
                     {1,0,1,0,0,0,0,1,1,1},
                     {1,0,1,0,1,1,0,1,1,1},
                     {1,0,0,0,0,1,0,1,1,1},
                     {1,1,1,1,1,1,0,1,1,1},
                     {1,1,1,1,1,1,0,1,1,1},
                     {1,1,1,1,1,1,0,1,1,1},
                     {1,1,1,1,1,1,0,1,1,1}};
    makemaze(adjmat);
    findpathfrom(3,1,7,6,adjmat);
    return 0;
}
