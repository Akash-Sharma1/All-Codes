#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int flag=0;
    for(int i=0;i<n-1;i++){
        if(a[i+1]<a[i]){
            flag =1;
            break;
        }
        else{
            a[i+1]-=a[i];
            a[i]=0;
        }
    }
    if(flag==0 && a[n-1]==0)
        cout<<"YES";
    else
        cout << "NO";
}