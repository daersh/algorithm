#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n ;
    int v=n;
    int l= n/10;
    int r= n%10;
    int temp;
    int cnt=0;

    while(1){
        cnt++;
        temp = (l+r)%10;
        //cout << l <<" + "<< r << " = " << temp <<"\n"; 
        l=r;
        r=temp;

        if(l*10+r==n){
            cout << cnt;
            return 0;
        }
    }

    return 0;
}