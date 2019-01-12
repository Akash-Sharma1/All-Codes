#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >>t;
    while(t--){
   long long g;
   cin >> g;
   long long arr[g];
   for(int i=0;i<g;i++){cin >> arr[i];}
   long long ans=0;
   long long n=0;
   map<long long,long long> mp;
   for(int i=0;i<g;i++){
       while(mp[arr[i]]==1 && n>=1){
           mp[arr[i-n]]=0;
           n--;
       }
           n++;
           mp[arr[i]]=1;
           ans+=(n)*(n+1)/2;

   }
   cout << ans;
    }
    return 0;
}