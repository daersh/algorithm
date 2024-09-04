#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    long long n , m ;
    cin >> n >> m;

    vector<long long> v;
    long long result =0;
    for(int i = 0; i < n; i++){
        long long num;
        cin >> num;
        v.push_back(num);
        result+= num;
    }   

    long long l = 0;
    long long r = 1e18;

    while(l+1<r){
        long long mid = (l+r)/2;

        long long cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += v[i]/mid;
            if(cnt >= m)
                l = mid;
        }
        
        // cout << "mid: " << mid << " cnt: " << cnt << endl;
        
        if(cnt < m){
            r = mid;
        }else{
            l = mid;
        }
    }

    long long lcnt=0, rcnt=0;
    for(int i= 0; i < n; i++){
        lcnt+= v[i]/l;
        rcnt+= v[i]/r;
    }
    // cout << "lcnt: " << lcnt << " l: "<< l <<'\n';
    // cout << "rcnt: " << rcnt << " r: "<< r << '\n';
    
    // cout << "result: " << result << endl;
    if(rcnt == m){
        result -= m*r;
        // cout << lcnt*l << '\n';
    }
    else {
        result -= m*l;
        // cout << rcnt*r << '\n';
    }
    cout << result;

    return 0;
}