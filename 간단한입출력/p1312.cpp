#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int a,b,n;
    cin >> a>> b>> n;
    // cout << (double)a/b<<'\n';
    for(int i=0; i< n; i++){
        a%=b;
        a*=10;
        // cout << a<<'\n';
    }
    cout << a/b;
}
