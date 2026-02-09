#include <iostream>
#include <vector>

using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
const ll DIV=1000000007;
const int LEN = 200001;
vector<int> vec;
vector<pll> seg(LEN*4,{0,0});

pll update(int loc,int s,int e, int idx){
    if(idx<s || e<idx) return seg[loc];
    if(s==e) return seg[loc]={seg[loc].first+1,seg[loc].second+idx};
    int m=(s+e)/2;
    pll l=update(loc*2,s,m,idx);
    pll r=update(loc*2+1,m+1,e,idx);
    return seg[loc]= {l.first +r.first, l.second + r.second};   
}
pll find(int loc, int s, int e, int st, int ed){
    if(ed<s||e<st) return {0,0};
    if(st<=s && e<=ed) return seg[loc];
    int m=(s+e)/2;
    pll l=find(loc*2,s,m,st,ed);
    pll r=find(loc*2+1,m+1,e,st,ed);
    return { (l.first + r.first), (l.second + r.second)};
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vec.resize(n);
    for(int i=0; i< n; i++) cin >> vec[i];   
    update(1,0,LEN-1,vec[0]);
   
    ll res=1;
    for(int i=1; i< n; i++) {
        int v = vec[i];
        pll l=find(1,0,LEN-1,0,v);
        pll r=find(1,0,LEN-1,v,LEN-1);
        res = (res*( (v*l.first-l.second)%DIV+ (r.second-v*r.first)%DIV)%DIV +DIV)%DIV;
        update(1,0,LEN-1,v);
    }
    cout << res%DIV;
}