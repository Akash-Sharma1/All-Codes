#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){cin >> arr[i];}
    vector<vector<int> > v;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            map<int,int> m;
            m[arr[j]]++;
            v[i].push_back(m.size());
        }
    }
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        cout<<v[a][b-a]<<endl;
    }
}
