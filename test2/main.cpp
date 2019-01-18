#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int tables,m;
        cin >> tables >> m;
        int arr[m];
        for(int i=0;i<m;i++){cin >> arr[i];}
        map<int,int> mape,freq;
        for(int i=0;i<m;i++){freq[arr[i]]++;}
        int k=0,count=0;
        int places[tables]={0};
        for(int i=0;i<m;i++){
            if(k<tables){
                if(mape[arr[i]]==0){
                    count++;
                    mape[arr[i]]=1;
                    freq[arr[i]]--;
                    places[k]=arr[i];
                    k++;
                }
                else{
                    //if it is already present
                    freq[arr[i]]--;
                }
            }
            else{
                //if tables are full and you have to make minimum frequency one get up
                if(mape[arr[i]]==0){
                    //if it is new
                    count++;
                    int minn=INT_MAX,index=-1;
                    for(int i=0;i<tables;i++){
                        if(freq[places[i]] < minn){
                            minn=freq[places[i]];
                            index=i;
                         }
                    }
                    mape[places[index]]=0;
                    places[index]=arr[i];
                    mape[arr[i]]=1;
                    freq[arr[i]]--;
                }
                else{
                    //it it is already on table
                    freq[arr[i]]--;
                }
            }
        }
        cout << count<<endl;
    }
}
