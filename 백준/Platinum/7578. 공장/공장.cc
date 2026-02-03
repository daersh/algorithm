#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> arr;
map<int,int> arr2;
vector<int> seg;
int n, a;
int update(int loc, int s, int e, int idx){
    if(idx<s || e<idx) return seg[loc];
    if(s==e) return seg[loc]=1;
    int m=(s+e)/2;
    return seg[loc]= update(loc*2,s,m,idx)+update(loc*2+1,m+1,e,idx);
}

int query(int loc, int s, int e, int st, int ed){
    if(ed < s || e < st) return 0;
    if(st<=s && e<= ed) return seg[loc];
    int m = (s+e)/2;
    return query(loc*2,s,m,st,ed)+query(loc*2+1,m+1,e,st,ed);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    arr.resize(n+1);
    seg.resize(n*4);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++){
        cin >> a;
        arr2[a]=i;
    }

    long long result =0;
    for (int i = 0; i < n; i++) {
        int idx= arr2[arr[i]];
        result += query(1,0,n-1,idx,n-1);
        update(1,0,n-1,idx);
        int cnt=1;
    }
    cout << result;
}
