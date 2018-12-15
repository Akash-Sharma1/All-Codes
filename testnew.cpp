#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> ideal;
    queue<int> current;
    int x;
    for(int i=0;i<n;i++){cin >> x;
        current.push(x);}
    for(int i=0;i<n;i++){cin >> x;
        ideal.push_back(x);}
    int count=0;
    for(int i=0;i<n;,i++){
        while(ideal[i]!=current.front()){
            int y=current.front();
            current.pop();
            current.push(y);
            count++;
        }
        current.pop();
        count++;
    }
    cout << count;
    return 0;
}
