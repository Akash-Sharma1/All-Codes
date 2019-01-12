#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){cin >> a[i];}
        int max1=0,max2=0,min1=INT_MAX,min2=INT_MAX;
        for(int i=0;i<n;i++){
            if(max1 < a[i]+i){max1=a[i]+i;}
            if(max2 < a[i]-i){max1=a[i]-i;}
            if(min1 > a[i]+i){min1=a[i]+i;}
            if(min1 > a[i]-i){min1=a[i]-i;}
        }
        int ans=max1-min1;
        if(ans < max1-min2){ans=max1-min2;}
        if(ans < max2-min2){ans=max2-min2;}
        if(ans < max2-min1){ans=max1-min1;}
        cout << ans <<endl;
    }
}