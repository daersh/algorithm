#include <iostream>
#include <vector>

using namespace std;
using ll = long long ;
using pll = pair<ll,ll>;
const int SIZE = 2000010;
const int MINUS = 500000;
int t, n,m;

vector<pll> seg;
ll increment;
// 1 a : a 값 추가 
// 2 a : 모든 수 a 증가  
// 3 a :  오름차순 a개
// 4 a :  내림차순 a개 

pll add(int loc, int s, int e, int idx) {
    if (idx < s || e < idx) return seg[loc];
    if (s == e) return seg[loc] = {seg[loc].first+1, seg[loc].second+s};
    
    int m = (s+e) / 2;
    pll l = add(loc*2, s, m, idx);
    pll r = add(loc*2+1, m+1, e, idx); 
    return seg[loc] = {l.first+r.first, l.second+r.second};
}

ll find_min(int loc, int s, int e, ll cnt) {
    if (cnt <= 0) return 0;
    if (seg[loc].first <= cnt) return seg[loc].second;
    if (s == e) return (ll)s*cnt;
    
    int m = (s+e) / 2;
    if (cnt <= seg[loc*2].first)
        return find_min(loc*2, s, m, cnt);
    
    return seg[loc*2].second+find_min(loc*2+1, m+1, e, cnt - seg[loc*2].first);
}

ll find_max(int loc, int s, int e, ll cnt) {
    if (cnt <= 0) return 0;
    if (seg[loc].first <= cnt) return seg[loc].second;
    if (s == e) return (ll)s*cnt;
    
    int m = (s+e) / 2;
    if (cnt <= seg[loc*2+1].first)
        return find_max(loc*2+1, m+1, e, cnt);
    
    return seg[loc*2+1].second+find_max(loc*2, s, m, cnt - seg[loc*2+1].first);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--){
        cin >> n >> m;
        seg.assign(SIZE*4,{0,0});
        increment = 0;
        ll a,b;

        for(int i=0; i< n; i++) {
            cin >> a;
            add(1,0,SIZE-1,a+MINUS);
        }
        for(int i=0; i<m;i++){
            cin >> a >> b;
            if(a==1){
                // add b
                add(1,0,SIZE-1,b - increment + MINUS);
            }else if(a==2){
                // add all b
                increment+=b;
            }else if(a==3){
                // less
                ll res = find_max(1,0,SIZE-1,b);
                cout << res+(increment-MINUS)*b <<' ';
            }else {
                // greater
                ll res = find_min(1,0,SIZE-1,b);
                cout << res+(increment-MINUS)*b <<' ';
            }
        }
        
        cout <<'\n';
    }
}