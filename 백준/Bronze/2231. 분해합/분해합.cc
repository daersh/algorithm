#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int loc=0;
    int sum=0;
    while(loc<=n){
        if(sum==n){
            cout << loc;
            return 0;
        }
        int v = ++loc;
        sum = v;
        // cout <<"v: "<< v ;
        while(v>0){
            sum+=v%10;
            v/=10;
        }
        // cout <<" sum: "<< sum;
        if(sum==n){
            cout << loc;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
