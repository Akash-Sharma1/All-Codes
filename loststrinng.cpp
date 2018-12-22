#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    string interval[k];
    while(n--){
        int l,r,z;
        cin >> l >> r >> z;
        int i=0;
        while(i<interval[z].size() && l>interval[z][i] && l>interval[z][i+1]){i+=2;}
            if(i>interval[z].size() || r< interval[z][i] ){
                //0-2   5-8
                //   3-4   9-10
                string str=l+""+r;
                string left=interval[z].substr(0,i);//starting pos , length
                string right=interval[z].substr(i);
                interval[z]=left+str+right;
            }
            //0-2  5--8
            //   3--6
            else if(l<interval[z][i] && r<interval[z][i+1]){
               interval[z][i]=l+"";
            }
            //0-2 5--8  10---13
            //     6--9
            //0-2 5--8 10--13
            //     6----11
           else if(l>interval[z][i] && r>interval[z][i+1]){
               while(r>interval[z][i]){
                   interval[z][i]=r+"";
                   i++;}
           }

    }
    int arr[m]={0};
    for(int j=0;j<k;j++){
        for(int i=0;i<interval[j].size();i++){
            int l=interval[j][i];
            int r=interval[j][i+1];
            for(;l<=r;l++){arr[l]++;}
            while(r<interval[j].size()-1 && interval[j][r]==interval[j][r+1]){i++;}
        }
    }
    long long prod=1;
    for(int i=0;i<m;i++){
        prod*=(k-arr[i]);
    }
    cout << prod%(1000000+3);
}