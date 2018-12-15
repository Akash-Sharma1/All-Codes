#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool issame(int * freq,int a){
  int c=a;
  bool flag=false;
  int f[10]={0};
  while(c){
    int temp=c%10;
    f[temp]=1;
    c/=10;
  }
  for(int i=0;i<10;i++){
    if(f[i]==1 && freq[i]==f[i]){
      flag=true;}
    else{
      freq[i]=0;}
  }
  if(flag){
    return true;}
  else{
        int c=a;
    while(c){
    int temp=c%10;
    freq[temp]=1;
    c/=10;
  }
  }
  return false;
}

int main(){
  int n;
  cin >> n;
  int arr[n];
  int freq[10]={0};
  int count=0,max=0;
  for(int i=0;i<n;i++){cin >> arr[i];}
  for(int i=0;i<n;i++){
    if(issame(freq,arr[i])){
      count++;
      if(max<count)
        max=count;
    }
    else{
      count=1;
      if(count > max)
        max=count;
    }
  }

  cout << max;
  return 0;
}
