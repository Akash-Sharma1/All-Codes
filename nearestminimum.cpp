#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
 // your code goes here
 int t;
 cin >> t;
 while(t--){
  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){cin >>arr[i];}
  int dist[n];
  stack<int> st;
  for(int i=0;i<n;i++){
   if(st.empty()){
    dist[i]=-1;
    st.push(arr[i]);
   }
   else if(st.top() < arr[i]){
    dist[i]=st.top();
    st.push(arr[i]);
   }
   else {
    while(!st.empty() && st.top() > arr[i]){
     st.pop();
    }
    if(st.empty()){
     dist[i]=-1;
    }
    else{
     dist[i]=st.top();
    }
    st.push(arr[i]);
   }
  }
  for(int i=0;i<n;i++){
   cout << dist[i]<<" ";
  }
 }
 return 0;
}