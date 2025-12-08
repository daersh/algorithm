#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    if(n>1500000)
        n %= 1500000;
    long long past1=0;
    long long past2=1;
    long long mod = 1000000;

    for(int i=2; i<=n;i++){
        long long s = (past1+past2)%mod;
        past1=past2;
        past2=s;
    }
    cout << past2;
    
}