#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
vector<int> seg;

long long cnt = 0;
long long total = 0;

int init(int loc, int s, int e){
    if(s==e) return seg[loc] = s;
    int mid = (s+e)/2;
    int l = init(loc*2, s, mid);
    int r = init(loc*2+1, mid+1, e);
    return seg[loc] = (v[l] < v[r]) ? l : r;
}

int find(int loc, int s, int e, int st, int ed){
    if(ed<s||e<st) return -1;
    if(st<=s&&e<=ed) return seg[loc];
    int mid = (s+e)/2;
    int l = find(loc*2, s, mid, st, ed);
    int r = find(loc*2+1, mid+1, e, st, ed);
    if(l==-1) return r;
    if(r==-1) return l;
    return (v[l] < v[r]) ? l : r;
}

void solve(int s, int e, long long past){
    int idx = find(1,0,v.size()-1,s,e);
    int val = v[idx] - past;
    cnt += (val/40) + (val%40/30) + (val%40%30/20) + (val%40%30%20/10);
    total += val;
    if(s < idx) solve(s, idx-1, v[idx]);
    if(idx+1 <= e) solve(idx+1, e, v[idx]);
}

int main(){
    int n;
    cin >> n;
    v.resize(n);
    seg.resize(4*n);

    for(int i=0; i<n; i++) cin >> v[i];

    init(1,0,n-1);
    solve(0, n-1, 20);
    cout << total*2 << " " << cnt*4;

}