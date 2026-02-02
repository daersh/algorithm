#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
vector<int> seg;
int n,m;

int update(int loc, int s, int e, int i, int ii){
    if(i<s || e< i) return seg[loc];
    if(s==e) return seg[loc]+=ii;
    int m=(s+e)/2;
    int l= update(loc*2,s,m,i,ii);
    int r= update(loc*2+1,m+1,e,i,ii);
    return seg[loc]= l+r;
}

int find(int loc, int s, int e, int v){
    if(s == e) return s;
    int m =(s+e)/2;
    if(seg[loc*2]>=v)
        return find(loc*2, s, m , v);
    else
        return find(loc*2+1, m+1,e,v-seg[loc*2]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >>n >> m;
    int mid = (m+1)/2;

    vec.resize(n+1);
    seg.resize(65540*4);

    for(int i=0;i<n;i++) cin >> vec[i];
    long long result=0;
    for(int i=0; i<n;i++){
        update(1,0,65535,vec[i],1);
        if(i<m-1) continue;
        result += find(1,0,65535,mid);
        update(1,0,65535,vec[i-m+1],-1);
    }
    cout << result;
}