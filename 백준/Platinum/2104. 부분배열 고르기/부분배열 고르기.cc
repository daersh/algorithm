#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> vec;
vector<ll> vec2;
vector<ll> seg;
int n;
ll res= 0;

ll init(int loc, int s, int e){
    if(s==e) return seg[loc]=s;
    int m = (s+e)/2;
    ll l = init(loc*2,s,m);
    ll r =init(loc*2+1,m+1,e);
    return seg[loc]= vec[l]<=vec[r]? l : r;
}   

ll query(int loc, int s, int e, int left, int right) {
    if (right < s || e< left ) return 0;
    if (left <= s && e <= right) return seg[loc];

    int mid = (s + e) / 2;
    int l = query(loc*2, s, mid, left, right);
    int r = query(loc*2+1, mid+1, e, left, right);
    if(!l) return r;
    if(!r) return l;

    return (vec[l] <= vec[r]) ? l : r;
}

ll find(int left, int right){
    if(left>right) return 0;
    if(left==right) return vec[left]*vec[left];

    int min_v= query(1,1,n,left,right);
    return max((vec2[right]-vec2[left-1])*vec[min_v], max(find(left,min_v-1),find(min_v+1,right)));
}

int main(){
    cin >> n;
    vec.resize(n+1);
    vec2.resize(n+1);
    seg.resize(n*4);
    for(int i=1; i<=n;i++) {cin >> vec[i];vec2[i]=vec[i]+vec2[i-1];}

    init(1,1,n);
    cout << find(1,n);
}