
#include<bits/stdc++.h>
using namespace std;
int main() {
 long long t;
 cin >> t;
 while(t--){
  long long n;
  cin >> n;
  long long arr[n];
  for(long long i=0;i<n;i++){cin >>arr[i];}
  long long dist[n];
  stack<long long> st;
  for(long long i=0;i<n;i++){
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
  stack<long long> st2;
  long long dist2[n];
  for(long long i=n-1;i>=0;i--){
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
  long long max=0,temp=0;
  for(long long i=0;i<n;i++){cout <<dist[i] <<" ";}
  cout <<endl;
  for(long long i=0;i<n;i++){cout <<dist2[i] <<" ";}
  cout<<endl;
  for(long long i=0;i<n;i++){
      long long a=-dist[i]+i,b=dist2[i]-i-1;
      if(dist[i]==-1){a=i+1;}
      temp=a+b;
      cout <<a<<" "<<b<<" "<<temp<<" -distance\n";
      temp*=arr[i];
      //cout <<dist[i] <<" " <<dist2[i] <<" " <<arr[i]<<" " << temp<<endl;
      if(max<temp){max=temp;}
  }
 cout <<max<<endl;
  
 }
}