#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <bits/stdc++.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

using namespace std;
int x,y;

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
void makemaze(int adjmat[10][10]){
    int x=5,y=40;
    for(int i=0;i<10;i++){
        y=40;
       for(int j=0;j<10;j++){

            if(adjmat[i][j]==1){
                printcube(y,x);
            }
        y+=4;
       }
       x+=2;
    }

}
void printhints(pair<int,int> visit[10][10],int sx,int sy,int dx,int dy){
    pair<int,int> a[4];
    int key=0;
    int c=0;
    while(dx!=sx || sy!=dy){
        dx=visit[dx][dy].first;
        c++;
        dy=visit[dx][dy].second;
        a[(key++)%4]=make_pair(dx,dy);
    }
    int m=min(c,4);
    for(int i=0;i<m;i++){
        int tempx=a[i].first;
        int tempy=a[i].second;
        cout << tempx <<" "<< tempy <<endl;
    }

}
void findpathfrom(int sx,int sy,int dx,int dy,int adjmat[10][10]){
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
        if((tempx-1)>=0 && adjmat[tempx-1][tempy]==0 && visit[tempx-1][tempy].first==-1){
            que.push(make_pair(tempx-1,tempy));
            visit[tempx-1][tempy]=make_pair(tempx,tempy);
        }
        if((tempx+1)<10 && adjmat[tempx+1][tempy]==0 && visit[tempx+1][tempy].first==-1){
            que.push(make_pair(tempx+1,tempy));
            visit[tempx+1][tempy]=make_pair(tempx,tempy);
        }
        if((tempy-1)>=0 && adjmat[tempx][tempy-1]==0 && visit[tempx][tempy-1].first==-1){
            que.push(make_pair(tempx,tempy-1));
            visit[tempx][tempy-1]=make_pair(tempx,tempy);
        }
        if((tempy+1)<10 && adjmat[tempx][tempy+1]==0 && visit[tempx][tempy+1].first==-1){
            que.push(make_pair(tempx,tempy+1));
            visit[tempx][tempy+1]=make_pair(tempx,tempy);
        }
    }
    printhints(visit,sx,sy,dx,dy);

}

void makeframe(){
    for(int i=10;i<=100;i++){
        gotoxy(i,5);
        cout<<"#";
         gotoxy(i,6);
        cout<<"#";
        gotoxy(i,25);
        cout<<"#";
         gotoxy(i,26);
        cout<<"#";
    }
    for(int i=5;i<=26;i++){
        gotoxy(10,i);
        cout<<"###";
        gotoxy(100,i);
        cout<<"###";
    }
  }
void printsnake(vector <pair<int,int> > snake){
      int k=0;
    for(int i=snake.size()-1;i>=k;i--){
        gotoxy(snake[i].first,snake[i].second);
        if(i!=0 && (snake[0].first==snake[i].first) && (snake[0].second==snake[i].second)){cout <<"X";k++;continue;}
        cout << "O";
    }

  }
void follow(vector <pair<int,int> > &snake,int prev,bool danger){

    for(int i=snake.size()-1;i>0;i--){
        snake[i].first=snake[i-1].first;
        snake[i].second=snake[i-1].second;
    }
    if(prev==UP){

            if(snake[0].second<=7 && danger==0){
                    snake[0].second=24;
                    return;}
        snake[0].second -=1;
        return;
    }
    if(prev==RIGHT){

            if(snake[0].first>=99 && danger==0){
                    snake[0].first=13;
                    return;}
        snake[0].first +=1;
        return;
    }
    if(prev==LEFT){
            if(snake[0].first<=13 && danger==0){
                    snake[0].first=99;
                    return;}
        snake[0].first -=1;
        return;
    }
    if(prev==DOWN){
            if(snake[0].second>=24 && danger==0){
                    snake[0].second=7;
                    return;}
        snake[0].second +=1;
        return;
    }
  }
bool checkmove(int prev,int dir){
    if(prev==UP && dir==DOWN){return false;}
    if(prev==DOWN && dir==UP){return false;}
    if(prev==LEFT && dir==RIGHT){return false;}
    if(prev==RIGHT && dir==LEFT){return false;}
    return true;
}
bool isdead(vector <pair<int,int> > snake,bool danger){
    for(int i=1;i<snake.size()-1;i++){
        if((snake[0].first==snake[i].first) && (snake[0].second==snake[i].second)){return true;}
    }
    if(danger==0){return false;}
    if(snake[0].first<=12 || snake[0].first>=100){return true;}
    if(snake[0].second<=6 || snake[0].second>=25){return true;}
    return false;
}
void placefruit(){
    gotoxy(x,y);
    cout<<"$";
}
bool eatenfruit(vector <pair<int,int> > snake){
    if(snake[0].first==x && snake[0].second==y){return true;}
    return false;
}
void addnode(vector <pair<int,int> > &snake,int prev,int &len){
    int last=snake.size();
    len++;
    int i=snake[last-1].first;
    int j=snake[last-1].second;
    switch(prev){
    case UP:
        snake.push_back(make_pair(i,j-1));
        break;
    case DOWN:
        snake.push_back(make_pair(i,j+1));
        break;
    case RIGHT:
        snake.push_back(make_pair(i-1,j));
        break;
    case LEFT:
        snake.push_back(make_pair(i+1,j));
        break;
    }

}
void changefruit(){
    x=rand() %85+12;
    y=rand() %18+7;
}
void showscore(int score,int highscore){
    gotoxy(25,3);
    cout <<"SCORE :: "<<score;
    gotoxy(75,3);
    cout <<"HIGHSCORE :: "<<highscore;}

int main()
{   int highscore=0;
    start:
    vector<pair<int,int> > snake;// head.......tail
    int len=5,score=0;
    int prev=RIGHT;
    changefruit();
    gotoxy(0,0);
    cout<<"\nCHOOSE LEVEL TO CONTINUE ::\n:: 1. WORMHOLE  \n:: 2. SOLID WALLS \n:: 3. MAZE \n:: ANY KEY TO EXIT \nYOUR SPEED WILL INCREASE ACCORDING TO YOUR SCORE\n";
    int level=50000000;
    bool danger=0;
    int l1;
    cin >>l1;
    if(l1>3){return 0;}
    if(l1==3){
            system("cls");
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
        int currx=0,curry=1;
        while(true){
            printuser(40+curry*4,5+2*currx);
            int key=getch();
            while(key==224)
                key=getch();
            if(key==84){
                    findpathfrom(currx,curry,6,9,adjmat);
            }
            if(key==UP && currx-1>=0 && adjmat[currx-1][curry]==0 ){
                removebackstep(40+curry*4,5+2*currx);
                currx--;
                printuser(40+curry*4,5+2*currx);
            }
            else if(key==DOWN && currx+1<10 && adjmat[currx+1][curry]==0){
                removebackstep(40+curry*4,5+2*currx);
                currx++;
                printuser(40+curry*4,5+2*currx);
            }
            else if(key==LEFT && curry-1>=0 && adjmat[currx][curry-1]==0){
                removebackstep(40+curry*4,5+2*currx);
                curry--;
                printuser(40+curry*4,5+2*currx);
            }
            else if(key==RIGHT && curry<10 && adjmat[currx][curry+1]==0){
                removebackstep(40+curry*4,5+2*currx);
                curry++;
                printuser(40+curry*4,5+2*currx);
            }

            }

    }
    if(l1==2){danger=1;}
    int i=1,j=1;

    lifeline:
        system("cls");
    makeframe();
    placefruit();
    showscore(score,highscore);
        snake.clear();
        for(int i=0;i<len;i++){snake.push_back(make_pair(len-i+12,10));}
////STARTING OF THE GAME
    while(1>0){
            int l=level;
            while(l--){}
        //PRINTING
        gotoxy(i,j);cout<<" ";
        printsnake(snake);
        //TAKING NEXT MOVE
        if(_kbhit()){
        input:
        int key=getch();
        if(key==224){goto input;}
        //CHECKING IF MOVE IS NOT OPPOSITE
        if(checkmove(prev,key)){prev=key;}
        }


        i=snake[snake.size()-1].first;
        j=snake[snake.size()-1].second;
        //MAKING THE SNAKE MOVE
        follow(snake,prev,danger);
        //CHECKING IF SNAKE HAS BITTEN A FRUIT
        if(eatenfruit(snake)){addnode(snake,prev,len);
                            printsnake(snake);
                            changefruit();
                            level-=1000000*score;
                            score++;
                            if(highscore<score){highscore++;}
                            showscore(score,highscore);
                            placefruit();
                            }
        //CHECKING IF SNAKE HAS BITTEN ITSELF OF NOT
        if(isdead(snake,danger)){
                gotoxy(i,j);cout<<" ";
                printsnake(snake);
                gotoxy(50,14);
                if(highscore>score){
                cout<<"HIGHSCORE WAS :: "<<highscore<<endl;
                gotoxy(50,13);
                cout<<"YOUR SCORE IS :: "<<score<<endl;}
                else{cout<<"NEW HIGHSCORE :: "<<highscore<<endl;}
                gotoxy(50,15);
                cout <<"YOUR GAME IS OVER";
                int temp;
                gotoxy(50,27);
                if(score<2){break;}
                cout<<"DO YOU WANT A LIFELINE FOR 2s POINTS PRESS 1 FOR YES";
                cin >> temp;
                if(temp!=1 ){break;}
                score-=2;
                goto lifeline;
                }

    }
    goto start;
     gotoxy(1,27);

    return 0;
}
