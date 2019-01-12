#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
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
    st.push(i);
   }
   else if(arr[st.top()] < arr[i]){
    dist[i]=st.top();
    st.push(i);
   }
   else {
    while(!st.empty() && arr[st.top()] >= arr[i]){
     st.pop();
    }
    if(st.empty()){
     dist[i]=-1;
    }
    else{
     dist[i]=st.top();
    }
    st.push(i);
   }
  }
  stack<int> st2;
  int dist2[n];
  for(int i=n-1;i>=0;i--){
      if(st2.empty()){
    dist2[i]=n;
    st2.push(i);
   }
   else if(arr[st2.top()] < arr[i]){
    dist2[i]=st2.top();
    st2.push(i);
   }
   else {
    while(!st2.empty() && arr[st2.top()] >= arr[i]){
     st2.pop();
    }
    if(st2.empty()){
     dist2[i]=n;
    }
    else{
     dist2[i]=st2.top();
    }
    st2.push(i);
   }
  }
  int max=0,temp=0;
  for(int i=0;i<n;i++){
      temp=dist2[i]-dist[i]-1;
      temp*=arr[i];
      cout <<dist[i] <<" " <<dist2[i] <<" " <<arr[i]<<" " << temp<<endl;
      if(max<temp){max=temp;}
  }
 cout <<max<<endl;
  
 }
 
 return 0;
}