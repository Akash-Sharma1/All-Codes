#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isdiv(long *arr,long n,long i,long *leftsum,long *rightsum){
    if(i-1>=0){
        *leftsum+=arr[i-1];
    }
    *rightsum-=arr[i];
    if((*leftsum+*rightsum)%3!=0){
        return false;
    }


    long ld1=0,ld2=0,ld=0;
    if(i-1>=0)
        ld1=arr[i-1];
    if(i+1<n)
        ld2=arr[n-1];
    ld=ld1+ld2;
    if(ld%2!=0 || ld%5!=0)
        return false;

    return true;
}


void constr(long *arr,long *seg,long nl,long nr,long i){
    if(nl==nr){
        seg[i]=arr[nl];
        return;
    }
    long mid=nl+(nr-nl)/2;
    constr(arr,seg,nl,mid,2*i+1);
    constr(arr,seg,mid+1,nr,2*i+2);
    seg[i]=seg[2*i+1]+seg[2*i+2];

}
long getsum(long *seg,long nl,long nr,long lr,long rr,long i){
    if(lr<=nl && nr<=rr)
        return seg[i];
    if(nl >rr || nr < lr )
        return 0;
    long mid=(nl+nr)/2;
    return (getsum(seg,nl,mid,lr,rr,2*i+1)+getsum(seg,mid+1,nr,lr,rr,2*i+2));
}
int main(){
  long n;
  cin >> n;
  long arr[n];
  long res[n]={0};

  for(long i=0;i<n;i++){cin >> arr[i];}
  long leftsum=0,rightsum=0;
  for(long j=0;j<n;j++){
        rightsum+=arr[j];
    }
  for(long i=0;i<n;i++){
    if(isdiv(arr,n,i,&leftsum,&rightsum))
        res[i]=1;
  }
   int x = (int)(ceil(log2(n)));
   int max_size = 2*(int)pow(2, x) - 1;
   long *seg = new long[max_size];
  constr(res,seg,0,n-1,0);
  long q;
  cin >> q;
  while(q--){
      long lr,rr;
      cin >> lr >> rr;
      cout << getsum(seg,0,n-1,--lr,--rr,0)<<endl;
  }
  return 0;
}
