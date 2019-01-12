#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    string str;
    cin >> str;
    int maxx=0;
    char x='g',y='k';
for(int j=0;j<2;j++){
    queue<char> qu;
    int k=0,i=0;
    while(i<n){
       if(str[i]==x){
           qu.push(x);
           int a=qu.size();
           maxx=max(a,maxx);
           i++;
       }
       else if(k < m){
           k++;
           qu.push(y);
           int a=qu.size();
           maxx=max(a,maxx);
           i++;
       }
       else if(!qu.empty()){
           if(qu.front()==y){k--;}
           qu.pop();
       }
       else{i++;}
    }
    x='k';
    y='g';
}
    cout << maxx;
    return 0;
}
