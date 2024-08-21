#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    unsigned long long n;

    cin >> n;
    cout << n << '\n';
    unsigned long long l, r,m;
    l=0;
    r= sqrt(n);    
    while(l+1<r){
        m= (l+r)/2;
        if(l*l < n)
            l=m;
        else    
            r=m;
    }
    cout << r;
    return 0;
}