#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> vec;
    int eMax = 0;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        vec.push_back(x);
        eMax = max(eMax, x);
    }

    int l = 1;
    int r = 1e9 ;
    int result = 1e9;
    while(l +1 < r){
        int mid = (l +r)/2;
        int cnt = 0;
        // mid: 구슬 나눠줄 갯수
        for(int i=0;i<m;i++){
            if(vec[i]<=mid){
                cnt++;
                continue;
            }
            cnt += vec[i]/mid;
            int c= mid;
            if(vec[i]%mid!=0)
                cnt++;
            
            // cout <<" c: "<< c <<' ';
            // cout << "cnt: " << cnt << '\n';
        }  

        if(cnt <= n){
            r=mid;
            result = min(result, mid);
        }
        else 
            l=mid;
    }
    int lcnt = 0;
    int rcnt = 0;
    for(int i=0; i<m; i++){
        if(vec[i]<=l){
            lcnt++;
            continue;
        }
        lcnt += vec[i]/l;
        int c= l;
        if(vec[i]%l!=0)
            lcnt++;
    }
    for(int i=0; i<m; i++){
        if(vec[i]<=r){
            rcnt++;
            continue;
        }
        rcnt += vec[i]/r;
        int c= r;
        if(vec[i]%r!=0)
            rcnt++;
    }
    // cout << "lcnt: " << lcnt << endl;
    // cout << "rcnt: " << rcnt << endl;
    if(lcnt<=n)
        cout << l;
    else 
        cout << r;
     
    // cout << result <<'\n';
}