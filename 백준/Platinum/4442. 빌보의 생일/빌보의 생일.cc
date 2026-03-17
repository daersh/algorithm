#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
vector<ll> seg;
int n;

ll find(int loc,int s, int e, int st, int ed){
    if(ed<s||e<st) return 0;
    if(st<=s&&e<=ed) return seg[loc];
    int m=(s+e)/2;
    return find(loc*2,s,m,st,ed) + find(loc*2+1,m+1,e,st,ed);
}

ll update(int loc, int s, int e, int st, int ed){
    if(ed<s||e<st) return seg[loc];
    if(s==e) return seg[loc]=seg[loc]+1;
    int m=(s+e)/2;
    return seg[loc]=update(loc*2,s,m,st,ed)+update(loc*2+1,m+1,e,st,ed);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(1){
        cin >> n;
        if(n==0) break;
        seg.assign(n*4,0);
        map<string,int> names;
        string input;
        for(int i=0; i<n;i++){
            cin >> input;
            names[input]=i;
        }
        ll res=0;
        for(int i=0; i<n;i++){
            cin >> input;
            int past = names[input];
            res += find(1, 0, n-1, past + 1, n - 1);
            update(1, 0, n-1, past, past);
        }
        cout << res<<'\n';
    }
}