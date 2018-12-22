#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long calc(long i,long j,long n){
    long smallest;
    if(j>i){
        if(j-i > i+n-j){smallest=i+n-j;}
        else{smallest=j-i;}
    }
    else{
        if(i-j > j+n-i){smallest=j+n-i;}
        else{smallest=i-j;}
    }
    return smallest;
}
int main(){
    long n;
    cin >> n;
    long arr[n];
    for(long i=0;i<n;i++){cin >> arr[i];}
    long sum=0;
    for(long i=0;i<n;i++){sum+=arr[i];}
    long k=sum/n;
    for(long i=0;i<n;i++){arr[i]=arr[i]-k;}
    long steps=0;

    for(long i=0;i<n;i++){
        if(arr[i]<=0)
            continue;
        priority_queue<pair<long,long>,vector<pair<long,long> >,greater<pair<long,long> > > pq;
        for(long j=0;j<n;j++){
            if(arr[j]<0){
                long smallest=calc(i,j,n);
                pq.push(make_pair(smallest,j));
            }
        }
        while(arr[i]){
            long d=pq.top().first;//distance from polong
            long j=pq.top().second;//indexof shortage
            pq.pop();
            long y=-1*arr[j];//amount of shortage
            long small=min(arr[i],y);
            arr[i]-=small;
            arr[j]+=small;

            steps+=d*small;
        }
    }
    cout << steps;
    return 0;
}
/* 5
2 3 6 9 10*/
