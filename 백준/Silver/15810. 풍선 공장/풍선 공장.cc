#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e13;
typedef long long ll;

int main(){
            ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


    ll n , m ; // n : 풍선 푸는사람   m: 풍선 갯수
    cin >> n >> m;

    vector<ll> vec;        // vec 선언

    for(int i = 0; i <n; i++){
        ll temp;
        cin >> temp;    // 입력
        vec.push_back(temp); // 벡터 값 push
    }
    
    ll l = 1;
    ll r = INF;

    while(l+1<r){
        ll mid = (l+r)/2;

        // mid: 분 
        // 몇분일 때 풍선 개수가 몇갠지 찾는거
        ll cnt = 0;

        for(int i =0; i <n;i++ ){
            cnt += mid/vec[i];
        }

        // cout << "cnt: " << cnt << '\n';  

        if(cnt < m)
            l = mid;
        else 
            r = mid;
    }

    // cout << "l: "<< l << " r: " << r << '\n';

    ll lcnt = 0;
    ll rcnt = 0;

    for( int i = 0 ; i < n ; i++ ){
        lcnt += l/vec[i];
        rcnt += r/vec[i];
    }

    if(lcnt == m)
        cout << l;
    else
        cout << r;

    return 0;
}