#include <iostream>
#include <vector>
using namespace std;
using ll= long long ;
const ll LMIN=-1e16;
int n,m;
ll a;
vector<ll> seg;

ll find(int loc,int s, int e, int st, int ed){
    if(ed<s || e<st ) return LMIN;
    if(st<=s && e<=ed) return seg[loc];
    int m=(s+e)/2;
    return max(find(loc*2,s,m,st,ed),find(loc*2+1,m+1,e,st,ed));
}

ll update(int loc,int s,int e,int idx,ll val){
    if (idx < s || e < idx) return seg[loc];
    if (s==e) return seg[loc]=val; 
    int m = (s+e)/2;
    return seg[loc]=max(update(loc * 2, s, m, idx,val), update(loc * 2 + 1, m + 1, e, idx,val));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    seg.resize(n*4,LMIN);
    ll result= LMIN;
    for(int i=0; i<n;i++){
        cin >> a;
        int st = max(i-m,0);
        int ed = i;
        ll vv=find(1,0,n-1,st,ed);
        ll loc_val = max(vv+a,a);
        
        update(1,0,n-1,i,loc_val);
        result = max(result,loc_val);
    }
    cout << result;
}
