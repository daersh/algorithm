#include <iostream>
#include <vector>
using namespace std;

vector<long long> vec;
vector<long long> seg;

int insert(int loc, int start, int end, int y, int z){
    // cout << "start,end: " << start<<','<<end<<'\n';
    if(start>y || end<y)
        return 0;
    if(start==end)
        return seg[loc]+=z;
    if(start<=y && y<=end)
        seg[loc]+=z;
    int mid = (start+end)/2;
    insert(loc*2, start, mid, y, z);
    insert(loc*2+1, mid+1, end, y, z);
    // cout << "l,r: "<<  l<<','<<r<<'\n';
    return seg[loc];
}

long long find(int loc, int start, int end, int y, int z){
    if(z<start|| y>end)
        return 0;
    if(y<=start && z>=end){
        // cout << seg[loc]<<'\n';
        return seg[loc];
    }
    if(start==end){
        return seg[loc];
    }
    int mid= (start+end)/2;
    long long l = find(loc*2,start,mid,y,z);
    long long r= find(loc*2+1,mid+1,end,y,z);
    // cout << "l,r: "<<  l<<','<<r<<'\n';
    return l+r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vec.resize(n+1);
    seg.resize(n*4);
    int x,y,z;
    for (int i = 0; i < m; i++){
        cin >> x>>y>>z;
        if(x==1){
            insert(1,1,n,y,z);
            // for (int j = 1; j < n*4; j++){
                // cout << seg[j]<<' ';
            // }cout << '\n';

        }else{
            cout << find(1,1,n,y,z)<<'\n';
        }
    }
    
}