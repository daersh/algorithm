#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long ;
int n,m;
vector<ll> inputs;
vector<ll> seg;

ll init(int loc, int s, int e){
    if(s==e) return seg[loc] = inputs[s];
    int m =(s+e)/2;
    return seg[loc] = init(loc*2,s,m)+init(loc*2+1,m+1,e);
}

ll update(int loc, int s, int e, int idx, int v){
    if(idx<s||e<idx) return seg[loc];
    if(s==e) return seg[loc]+=v;
    int m = (s+e)/2;

    return seg[loc] = update(loc*2,s,m,idx,v) + update(loc*2+1,m+1,e,idx,v);
}

ll find(int loc, int s, int e, int idx){
    if(s==e) return s;
    int m = (s+e)/2;
    if(seg[loc*2] >= idx) return find(loc*2,s,m,idx);
    else return find(loc*2+1,m+1,e, idx-seg[loc*2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n ;
    inputs.resize(n+1);
    seg.resize(n*4);
    int num=0, x;
    for(int i=1; i<= n;i++) cin >> inputs[i];
    
    init(1,1,n);

    cin >> m;
    int a, b, c; 
    for(int i=0; i<m;i++){
        cin >> a;
        if(a==1){
            cin >> b>> c;
            update(1,1,n,b,c);
        }else{
            cin >> b;
            cout << find(1,1,n,b) <<'\n';
        }
    }
}