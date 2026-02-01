#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
vector<ll> vec;
vector<ll> seg;
int n,m, a,b,c,d;
vector<pair<int,int> > asdf;
map<int, vector<pair<int,pair<int,int> > > > asdf2;
map<int, ll> result;

ll init(int loc, int s, int e){
    if(s==e) return seg[loc]=vec[s]; 
    int m= (s+e)/2; 
    return seg[loc]= init(loc*2,s,m)+init(loc*2+1,m+1,e); 
}

ll find(int loc, int s, int e, int l, int r){
    if(r<s || e < l) return 0;
    if(l<=s && e <=r) return seg[loc];
    int m= (s+e)/2;
    ll next= find(loc*2,s,m,l,r)+find(loc*2+1,m+1,e,l,r);
    return next;
}

ll add(int loc, int s, int e, int d, int v){
    if(d<s||e<d) return seg[loc];
    if(s==e) return seg[loc] = v;
    int m = (s+e)/2;
    return seg[loc]=add(loc*2,s,m,d,v)+add(loc*2+1,m+1,e,d,v);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;    
    vec.resize(n+1);
    seg.resize(n*4);
    for(int i=0; i< n ; i++) cin >> vec[i];
    
    init(1,0,n-1);
    cin >> m;
    int cnt=0;
    for(int i=1; i< m+1 ; i++){
        cin >> a;
        if(a==1){
            cin >> b >> c;
            asdf.push_back({b,c});
            cnt++;
        }
        if(a==2){
            cin >> b>> c >> d;
            asdf2[b].push_back({i, {c-1,d-1}});
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<asdf2[i].size();j++) 
            result[asdf2[i][j].first]= find(1,0,n-1,asdf2[i][j].second.first,asdf2[i][j].second.second);
        if(i<cnt)
            add(1,0,n-1,asdf[i].first-1,asdf[i].second);
    }

    for(int i=0; i< m+1;i++){
        if(result[i]!=0)
            cout << result[i]<<'\n';
    }
    
}