#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> vec;
vector<int> seg;

int init(int loc, int start, int end){
    if(start==end)
        return seg[loc]= start;
    int mid= (start+end)/2;
    int l= init(loc*2, start, mid);
    int r= init(loc*2+1, mid+1, end);
    return seg[loc] = vec[l]<=vec[r]? l : r ;
}
int find(int loc, int start, int end, int x, int y){
    // cout << "start,end: " << start <<','<<end<<'\n';
    if(x>end || y<start){
        // cout << "... return 0\n";
        return 0;
    }
    if(x<=start && end <= y){
        // cout << "seg[loc]: " << seg[loc]<<'\n';
        return seg[loc];
    }
    int mid= (start+end)/2;
    int l= find(loc*2, start, mid, x,y);
    int r= find(loc*2+1, mid+1, end, x,y);
    // cout << "l,r: " << l <<','<<r<<'\n';
    // cout << "vec[l],vec[r]"<< vec[l] <<','<<vec[r]<<'\n';
    return vec[l]<=vec[r]? l :r;
}

int change(int loc, int start, int end, int target, int value){
    if(target<start || target>end)
        return seg[loc];
    if(start == end){
        // cout << "found\n";
        vec[target]=value;
        return seg[loc]= target;
    }
    int mid = (start+end)/2;
    int l=change(loc*2,start,mid,target,value);
    int r=change(loc*2+1,mid+1,end,target,value);
    // cout << "l,r: " << l <<','<<r<<'\n';
    // cout << "vec[l],vec[r]"<< vec[l] <<','<<vec[r]<<'\n';
    return seg[loc] = vec[l]<=vec[r]? l : r ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >>n;
    vec.resize(n+1);
    seg.resize(n*4);
    vec[0]=1000000002;
    for(int i=1; i<=n;i++){
        cin >> vec[i];
    }
    init(1,1,n);
    // for (int i = 0; i < n*4; i++){cout << seg[i]<< ' ';}cout<<'\n';
    
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b>> c;
        if(a==2){
            cout << find(1,1,n,b,c)<<'\n';
            continue;
        }
        change(1,1,n,b,c);
    }
    
}