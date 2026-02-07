#include <iostream>
#include <vector>

using namespace std; 
vector<int> vec;
vector<int> seg;
int n;
long long result=0;

int init(int loc, int s, int e){
    if(s==e) return seg[loc] = s;
    int m = (s+e)/2;
    int l = init(loc*2,s,m);
    int r = init(loc*2+1,m+1,e);
    return seg[loc]= (vec[l]<=vec[r])?l:r;
}

int find(int loc, int s, int e, int st, int ed){
    if(ed<s||e<st) return n;
    if(st<=s&&e<=ed) return seg[loc];
    int m = (s+e)/2;
    int l = find(loc*2,s,m,st,ed);
    int r = find(loc*2+1,m+1,e,st,ed);
    return (vec[l]<=vec[r])?l:r;
}

void eboon(int s, int e){
    int min_loc = find(1,0,n-1,s,e);
    result = max(result, (long long)vec[min_loc]*(e-s+1));
    if(s<min_loc-1)eboon(s,min_loc-1);
    if(e>min_loc+1)eboon(min_loc+1,e);
}


int main(){
    cin >> n;
    vec.resize(n+1);
    vec[n]=1e9;
    seg.resize(n*4);
    for(int i=0; i< n ;i++)cin >> vec[i];
    init(1,0,n-1);
    eboon(0,n-1);
    cout << result;
}