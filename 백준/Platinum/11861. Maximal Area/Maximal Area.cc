#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
int n;
vector<int> vec, seg;

int init(int loc, int s, int e){
    if(s==e) return seg[loc]= s;
    int m = (s+e)/2;
    int l=init(loc*2, s, m);
    int r=init(loc*2+1, m+1, e);
    return seg[loc]= vec[l] <= vec[r] ? l : r;
}

int find(int loc, int s, int e, int st, int ed){
    if(ed <s || e<st) return -1;
    if(st <= s && e <= ed) return seg[loc];
    int m = (s+e)/2;
    int l = find(loc*2, s, m, st, ed);
    int r = find(loc*2+1, m+1, e, st, ed);
    if(l == -1) return r;
    if(r == -1) return l;
    return vec[l] <= vec[r] ? l : r;
}
ll result=0;
void solve(int s, int e){
    int loc = find(1, 0, n-1, s, e);
    result = max(result, (ll)(e-s+1)*vec[loc]);
    if(s <= loc-1) solve(s, loc-1);
    if(loc+1 <= e) solve(loc+1, e);
}

int main(){
    cin >> n;
    vec.resize(n);
    seg.resize(n*4);
    for(int i=0; i<n; i++) cin >> vec[i];
    init(1, 0, n-1);
    solve(0, n-1);
    cout << result;
}