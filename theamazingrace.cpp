#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long arr[n];
        for(long long i=0;i<n;i++){cin >> arr[i];}
        stack<long long> st1,st2;
        long long dist1[n],dist2[n];
        for(long long i=0;i<n;i++){
            if(st1.empty()){
                dist1[i]=0;
                st1.push(i);
            }
            else{
                while(!st1.empty() && arr[st1.top()] < arr[i]){
                    st1.pop();
                }
                if(st1.empty()){
                    dist1[i]=0;
                    st1.push(i);
                }
                else{
                    dist1[i]=st1.top();
                    st1.push(i);
                }
            }
        }
        for(long long i=n-1;i>=0;i--){
            if(st2.empty()){
                dist2[i]=n-1;
                st2.push(i);
            }
            else{
                while(!st2.empty() && arr[st2.top()] < arr[i]){
                    st2.pop();
                }
                if(st2.empty()){
                    dist2[i]=n-1;
                    st2.push(i);
                }
                else{
                    dist2[i]=st2.top();
                    st2.push(i);
                }
            }
        }
        for(long long i=0;i<n;i++){cout <<dist1[i] <<" ";}
        cout <<endl;
        for(long long i=0;i<n;i++){cout <<dist2[i] <<" ";}
        cout<<endl;

        long long maxx=-1,index=-1;
        for(long long i=0;i<n;i++){
            //cout <<-dist1[i]+i <<" "<<dist2[i]-i<<endl;
            if(maxx<=(i+1)*(-dist1[i]+i+dist2[i]-i)%(1000000007)){
                maxx=(i+1)*(-dist1[i]+i+dist2[i]-i)%(1000000007);
                index=i+1;
            }
        }
        cout<<index<<endl;
    }
}