#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    map<int,int> m;
    for(int i=0;i<k;i++){
        m[arr[i]]++;
    }
    auto itr=m.rbegin();
    while(itr->second==0){
        itr--;   }
    cout << itr->first <<" ";
    for(int i=k,j=0;i<n;i++,j++){
        if(m[arr[j]]==1)
            m.erase(arr[j]);
        else
            m[arr[j]]--;
        m[arr[i]]++;
        itr=m.rbegin();
        while(itr->second==0){
            itr--;
        }
        cout << itr->first <<" ";
    }
}
