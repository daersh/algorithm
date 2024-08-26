#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    long long n , m ;

    cin >> n >> m;
    long long x;
    vector<long long> vec;
    long long minV = 1e9;
    for(long long i = 0; i < n; i++){
        cin >> x;
        vec.push_back(x);
        minV = min(minV, x); 
    }

    long long l = 0;
    long long r = minV* m;
    
    while (l+1<r)
    {
        long long mid = (l+r)/2;
        long long cnt = 0;  
        for(long long i = 0; i < n; i++){
            cnt+= mid/vec[i];
            if(cnt >= m){
                break;
            }
        }

        if(cnt >=m){
            r= mid;
        }else
            l= mid;
        // cout << mid << '\n';
    }
    
    long long lcnt = 0;
    long long rcnt = 0;

    for(long long i = 0; i < n; i++){
        lcnt+= l/vec[i];
        rcnt+= r/vec[i];
    }

    if(lcnt >= m)
        cout << l;
    else   
        cout << r;
    
    return  0;
}
