#include <iostream>
#include <vector>

using namespace std;
using ll =long long;
vector<int> arr;
vector<int> seg;

int init(int loc, int s, int e){
    if(s==e) return seg[loc] = s;

    int m = (s+e)/2;
    int l = init(loc*2, s,m);
    int r = init(loc*2+1,m+1,e);

    return seg[loc]= (arr[l]<=arr[r])? l:r;
}

int find(int loc, int s, int e, int l, int r){
    if(r<s || e<l) return -1;
    if(l<=s && e<=r) return seg[loc];

    int m = (s+e)/2;
    int lv = find(loc*2,s,m,l,r);
    int rv = find(loc*2+1,m+1,e,l,r);
    if(lv==-1) return rv;
    if(rv==-1) return lv;
    return (arr[lv]<=arr[rv])? lv:rv;
}

ll nulbi(int s, int e, int n){
    int loc = find(1,0,n-1,s,e);
    ll v = (ll)((e-s+1) * arr[loc]);
    if(s <= loc-1)v = max(v, nulbi(s,loc-1,n));
    if(loc+1 <= e) v = max(v, nulbi(loc+1,e,n));
    return v;
}

int main(){
    int n;
    cin >> n; 
    arr.resize(n+1);
    seg.resize(n*4);
    for(int i=0; i<n;i++) cin >> arr[i];
    init(1,0,n-1);
    cout << nulbi(0,n-1,n);
}