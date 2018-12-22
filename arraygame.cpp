#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int a[n],b[m];
    for(int i=0;i<n;i++){
        cin >> a[i];}
    for(int i=0;i<m;i++){
        cin >> b[i];}
        priority_queue<int,vector<int> ,greater<int> > pqa;
        priority_queue<int> pqb;
    for(int i=0;i<n;i++){
        pqa.push(a[i]);}
    for(int i=0;i<m;i++){
        pqb.push(b[i]);}
    int steps=0;
    while(!pqa.empty() && !pqb.empty()){
        int x=pqa.top();//smallest of a[]
        int y=pqb.top();//largest of b[]
        pqa.pop();
        pqb.top();
        if(x >= y){break;}
        if()
    }
    cout<< steps;
    return 0;
}