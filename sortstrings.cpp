#include<iostream>
#include<string>
#include<string.h>
using namespace std;
void stringsort(char *sarr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(strcmp(sarr[j],sarr[j+1])>0){
                char * temp;
                temp=sarr[j];
                sarr[j]=sarr[j+1];
                sarr[j+1]=temp;
            }
        }
    }
}
int main(){
    int n;
    n=10;
    char* sarr[n]={"abc","sdf","qwe","asg","dce","xws","bgr","dsd","ewr","fder"};
    stringsort(sarr,n);
    for(int i=0;i<n;i++){cout << sarr[i]<<endl;}
    return 0;
}