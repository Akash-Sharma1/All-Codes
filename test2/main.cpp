#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findindex( vector<int> &curr,int x,int j){
    int i=j;
    for(;i<curr.size();i++){
        if(curr[i]==x){
            curr.erase(curr.begin()+i);
            return i;}
    }
    return i;
}
int main(){
    int n;
    cin >> n;
    vector<int> ideal;
    vector<int> current;
    int x;
    for(int i=0;i<n;i++){cin >> x;
        current.push_back(x);}
    for(int i=0;i<n;i++){cin >> x;
        ideal.push_back(x);}
    int count=0,j=0;
    for(int i=0;i<n;i++){
        if(current[j]==ideal[i]){
            count++;
            j++;
        }
        else{
            int index=findindex(current,ideal[i],j+1);
            count+=index-j+1;
        }
    }
    cout << count;
    return 0;
}
