#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<char> qu;
    qu.push('g');
    qu.push('g');
    qu.push('g');
    qu.push('g');
    int a= qu.size();
    int b=5;
    cout << max(qu.size(),b);

    return 0;
}