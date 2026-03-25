#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;
using pii= pair<int,int>;

int n,m,k;
vector<int> vec;
vector<pii> seg;

pii comp(pii a, pii b){
    if(a.first==b.first) return a.second<b.second? a : b;
    return a.first>b.first ? a : b;
}

pii init(int loc, int s, int e){
    if(s==e) return seg[loc]= {vec[s] - s, s}; 
    int mid =(s+e)/2; 
    return seg[loc] = comp(init(loc*2,s,mid), init(loc*2+1,mid+1,e));
}

pii find(int loc, int s, int e, int st, int ed){
    if(ed<s||e<st) return {-1e9,-1e9};
    if(st<=s&&e<=ed) return seg[loc];
    int m = (s+e)/2;
    return comp(find(loc*2,s,m,st,ed), find(loc*2+1,m+1,e,st,ed));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    vec.resize(n*2);
    seg.resize(n*8);
    int max_v=0;
    for(int i=0;i<n;i++) {
        cin >> vec[i];
        max_v= max(vec[i],max_v);
    }
    for(int i=n;i<n*2;i++)
        vec[i]= vec[i-n];
    init(1,0,n*2-1);
    ll res = 0;
    vector<int> v2(n);
    for(int i=0; i< n;i++){
        int st = i;
        int ed = i+k-1;
        pii p1 = find(1, 0, n*2-1, st, ed); 
        int p1v = p1.first + k + st -1; 
        res += max(max_v, p1v);
        v2[i]= max(max_v, p1v);
        // cout << res <<'\n';
    }
    ll result = (m/n)*res;
    for(int i =0; i< m%n;i++)
        result += v2[i];
    cout << result;
}