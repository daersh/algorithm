#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii= pair<int,int>;
vector<pii> vec;
vector<int> seg;
int n,m,a,b;

int update(int loc, int s, int e, int idx){
    if (idx < s || e < idx) return seg[loc];
    if (s==e) return seg[loc]+=1; 
    int m = (s + e) / 2;
    return seg[loc]=update(loc * 2, s, m, idx)+update(loc * 2 + 1, m + 1, e, idx);
}

int find(int loc, int s, int e, int st, int ed){
    if(ed<s||e<st) return 0;
    if(st<=s&&e<=ed) return seg[loc];
    int m = (s+e)/2;
    return find(loc*2,s,m,st,ed)+find(loc*2+1,m+1,e,st,ed);
}

bool compare(pii a, pii b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    seg.resize(n*4);
    long long result=0;
    for(int i=0; i<m;i++){
        cin >> a >> b;
        a--;b--;
        vec.push_back({a,b});
    }
    sort(vec.begin(),vec.end(),compare);
    for(int i=0; i<m;i++){
        pii v= vec[i];
        result+=find(1,0,n-1,v.second+1,n-1);
        update(1,0,n-1,v.second);
    }
    cout <<result;
}