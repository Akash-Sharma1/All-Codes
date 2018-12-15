#include <iostream>
#include <math.h>
using namespace std;
int lcm(int n1,int n2){
    int max=0;
    max = (n1 > n2) ? n1 : n2;
    do
    {
        if (max % n1 == 0 && max % n2 == 0)
            return max;
        else
            ++max;
    } while (true);
    return max;
}
bool div(int n,int *a,int *b){
    if((*a)%n!=0 || (*b)%n!=0)
        return false;
    while((*a)%n==0 && (*b)%n==0 ){
        *a=(*a)/n;
        *b=(*b)/n;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        int turn=0,i=1,j=1,leftx=0,lefty=1,rightx=1,righty=1;
        int ridgex=0,ridgey=1;
        while(turn!=x){
            int lc=lcm(righty,lefty);
            ridgey=lc;
            ridgex=leftx*(lc/lefty)+rightx*(lc/righty);
            if(ridgex>=2 && ridgex%2==0)
                ridgex/=2;
            else
                ridgey*=2;

            if(turn %2 ==0){
                rightx=ridgex;
                righty=ridgey;
            }
            else{
                leftx=ridgex;
                lefty=ridgey;
            }
            turn++;
        }
        cout << ridgex << " " << ridgey << endl;
    }
    return 0;
}
