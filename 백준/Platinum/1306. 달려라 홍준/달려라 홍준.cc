#include <iostream>
#include <vector>

using namespace std;
vector<int> vec;
vector<int> seg;
int n,m; 

int init(int loc, int s, int e){
    if(s==e) return seg[loc]=vec[s];
    int m = (s+e)/2;
    return seg[loc]= max(init(loc*2,s,m),init(loc*2+1,m+1,e));
}

int find(int loc, int s, int e, int st, int ed){
    if(ed<s || e < st) return 0;
    if(st<=s&&e<=ed) return seg[loc];
    int m=(s+e)/2;
    return max(find(loc*2,s,m,st,ed),find(loc*2+1,m+1,e,st,ed));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vec.resize(n);
    seg.resize(n*4);
    for(int i=0; i< n; i++)cin>>vec[i];

    init(1, 0,n-1);

    int st =0;
    int ed =(m-1)*2;
    int max_v=0;
    while(ed<n){
        // cout << "st,ed: "<< st<< ','<<ed<<'\n';
        int cur_max = find(1,0,n-1,st,ed);
        st++;
        ed++;
        cout << cur_max<<' ';
    }

}