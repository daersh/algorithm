#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pii = pair<int,int>;

vector<int> vec;
vector<pii> seg;

pii comp(pii a, pii b){
    return {min(a.first, b.first),max(a.second,b.second)};
}

pii init(int l, int s, int e) {
    if(s==e) return seg[l] = {vec[s],vec[s]};
    int m = (s+e)/2;
    return seg[l] = comp(init(l*2,s,m), init(l*2+1,m+1,e));
}

pii find(int l, int s, int e, int x, int y){
    if(x>e || y<s) return {1e9, -1e9};
    if(x<=s && e <=y) return seg[l];
    int m= (s+e)/2;
    return comp(find(l*2,s,m,x,y), find(l*2+1,m+1,e,x,y));
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m ;
    cin >> n >> m;
    vec.resize(n+1);
    seg.resize(n*4);
    for(int i=1;i<=n;i++) cin >> vec[i];
    init(1,1,n);
    int a,b;
    for (int i = 0; i < m; i++) {
        cin >> a>> b;
        pii res = find(1,1,n,a,b);
        cout << res.second-res.first <<'\n';
    }

}