#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool check(int *arr,int n){
    map <int,int> visited;
        map <int,int> counted;
        for(int i=0;i<n;i++){
            if(visited[arr[i]]==0){
                visited[arr[i]]=1;
                if(counted[arr[arr[i]-1]]==1)
                    return true;
                counted[arr[arr[i]-1]]=1;

            }
        }
    return false;
}
int main(){
    int t;
    cin >> t;
    while(t--){
       int n;
       cin >> n;
       int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        (check(arr,n)) ? cout << "Truly Happy"<<endl : cout << "Poor Chef" <<endl;
    }
    return 0;
}
