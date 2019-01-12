#include <iostream>
using namespace std;
int main(){
    int k,n;
    cin >> k>> n;
    int arr[n];
    for(int i=0;i<n;i++){cin>>arr[i];}
    int sum[n]={0};
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]-arr[i]>=k){
                if(sum[i]+1>sum[j]){
                    sum[j]=sum[i]+1;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){ans=max(sum[i],ans);}
    cout<<ans+1;

}