#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long x, y;
    cin >> x >> y;
    
    long long z = y*100/x +1;
    long long l = y;
    long long r = 100000000000000;
    // cout << x << " " << y << " " << z << endl;

    while(l+1 < r){

        long long mid = (l+r)/2;

        if(mid*100/(x+mid-y) <z){
            l = mid;

        }else{

            r= mid;
        }

    }

    if(r*100/(x+r-y) <z){
        cout << -1;
        return 0;
    }


    cout << r-y << endl;
    return 0;

}