#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string str;
        cin >> str;
        int k=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='K'){
                k++;}
        }
        int min=INT_MAX;
        for(int i=0;i<str.length();i++){
                int c=k,count=0;
                while(c-- ){
                    if(i==str.length()){i=0;l=1;}
                    if(str[i++]=='D'){count++;}
                }
                if(min > count){count=min;}
                if(l==1){break;}
            }
        cout << min <<endl;
    }
    return 0;
}