#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long n ,m;
    cin >> n >> m ;
    vector<long long> vec;
    long long r=0;
    for(long long i = 0; i < n; i++){
        long long x;
        cin >> x;
        vec.push_back(x);
        if(x>r)
            r=x;
    }
    long long l = 0;

    while(l+1<r){
        long long mid = (l+r)/2;
        long long cnt = 0;
        for(long long i = 0; i < n; i++){
            cnt += vec[i]/mid;
        }
        if(cnt >= m){
            l = mid;
        }else{
            r = mid;
        }
    }
    
    long long lcnt = 0;
    long long rcnt = 0;
    for(long long i = 0; i < n; i++){
            lcnt += vec[i]/l;
            rcnt += vec[i]/r;
    }
    if(rcnt >= m)
        cout<< r;
    else
        cout << l;

}