#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int n;
ll result=0;
pii res_loc;
vector<int> arr;
vector<ll> seg;
vector<ll> seg2;

ll init(int loc, int s, int e){
    if(s==e) return seg[loc]=arr[s];
    return seg[loc]=init(loc*2,s,((s+e)/2))+init(loc*2+1,((s+e)/2)+1,e);
}

ll find(int loc, int s, int e, int st, int ed){
    if(ed<s||e<st) return 0;
    if(st<=s&&e<=ed) return seg[loc];
    return find(loc*2,s,((s+e)/2),st,ed)+find(loc*2+1,((s+e)/2)+1,e,st,ed);
}

int init2(int loc, int s, int e){
    if(s==e) return seg2[loc]=s;
    int l = init2(loc*2,s,((s+e)/2));
    int r = init2(loc*2+1,((s+e)/2)+1,e);
    return seg2[loc]=(arr[l]<=arr[r])?l:r;
}

ll find2(int loc, int s, int e, int st, int ed){
    if(ed<s||e<st) return -1;
    if(st<=s&&e<=ed) return seg2[loc];
    int l=find2(loc*2,s,((s+e)/2),st,ed);
    int r=find2(loc*2+1,((s+e)/2)+1,e,st,ed);
    if(l==-1) return r;
    if(r==-1) return l;
    return (arr[l]<=arr[r])?l:r;
}

void solve(int st,int ed){
    int idx = find2(1,0,n-1,st,ed);
    ll l= find(1,0,n-1,st,ed)*arr[idx];
    if(l>result){
        result = l;
        res_loc={st,ed};
    }
    if(st<=idx-1) solve(st,idx-1);
    if(idx+1<=ed) solve(idx+1,ed);
}


int main(){
    cin >>n;
    arr.resize(n);
    seg.resize(n*4);
    seg2.resize(n*4);
    for(int i=0;i<n;i++)cin >> arr[i];
    init(1,0,n-1);
    init2(1,0,n-1);
    solve(0,n-1);
    cout << result<<'\n'<<res_loc.first+1<<' '<<res_loc.second+1;
}