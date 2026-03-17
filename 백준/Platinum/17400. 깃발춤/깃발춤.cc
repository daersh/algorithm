#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using pii = pair<long long,long long>;
int n, m, a,b,c;
vector<int> vec;
vector<pii> seg;

pii init(int loc, int s, int e){
    if(s==e) {
        if(s%2==0)
            return seg[loc]=make_pair(vec[s],0);
        return seg[loc]=make_pair(0,vec[s]);
    }
    int m =(s+e)/2;
    pii l = init(loc*2,s,m);
    pii r = init(loc*2+1,m+1,e);
    return seg[loc]= make_pair(l.first+r.first,l.second+r.second);
}

pii find(int loc, int s, int e, int st, int ed){
    if(ed<s||e<st) return {0,0};
    if(st<=s&&e<=ed) return seg[loc];
    int m = (s+e)/2;
    pii l = find(loc*2,s,m,st,ed);
    pii r = find(loc*2+1,m+1,e,st,ed);
    return make_pair(l.first+r.first,l.second+r.second);
}

pii change(int loc, int s, int e, int idx, long long v){
    if(idx<s ||e<idx)         
        return seg[loc];

    if(s==e) 
        if(s%2==0)
            return seg[loc]=make_pair(v+seg[loc].first,0);
        else 
            return seg[loc]=make_pair(0,v+seg[loc].second);

    int m= (s+e)/2;
    pii l = change(loc*2,s,m,idx,v);
    pii r = change(loc*2+1,m+1,e,idx,v);
    return seg[loc]=make_pair(l.first+r.first,l.second+r.second);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vec.resize(n+1);
    seg.resize(n*4);
    for(int i=0; i< n ; i++) cin >> vec[i];
    init(1,0,n-1);
    for(int i=0; i< m; i++){
        cin >> a >> b>> c;
        if(a==1){
            pii res=find(1,0,n-1,b-1,c-1);
            // cout << res.first <<' '<< res.second<<'\n';
            cout << abs(res.first-res.second)<<'\n';
        }else{
            change(1,0,n-1,b-1,c);
        }
    }
}