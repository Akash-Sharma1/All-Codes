#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
map<int,int> m;
unordered_map <int,int> um;
for(int j=0;j<5;j++)
{for(int i=j;i<5;i++){
    m[i]++;
    um[i]++;
}
}
for(auto i=m.begin();i!=m.end();i++){cout<<i->first <<" m " << i->second<<endl;}
cout<<endl;
for(auto i=um.begin();i!=um.end();i++){cout<<i->first <<" um " << i->second<<endl;}
return 0;
}
