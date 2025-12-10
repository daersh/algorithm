#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
vector<int> seg;
int INF = 1000000002;

int init(int loc, int start ,int end){
    if(start==end)
        return seg[loc] = vec[start];
    int mid=(start+end)/2;
    int l= init(loc*2,start,mid); 
    int r= init(loc*2+1,mid+1,end); 
    return seg[loc] = l<=r? l : r;
}

int find(int loc, int start, int end, int x, int y){
    if(x>end || y<start)
        return INF;
    if(x<=start && y>=end)
        return seg[loc];
    int mid = (start+end)/2;
    int l= find(loc*2,start,mid,x,y);
    int r= find(loc*2+1,mid+1,end,x,y);
    return l<=r? l : r;
}

int change(int loc, int start, int end, int target, int value){
    if(target<start || target>end) 
        return seg[loc];
    if(start==end){
        vec[target]=value;
        return seg[loc]= value;
    }
    int mid=(start+end)/2;
    int l= change(loc*2,start,mid,target,value);
    int r= change(loc*2+1,mid+1,end,target,value);
    return seg[loc] = l<=r? l : r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n ;
    vec.resize(n+1);
    seg.resize(n*4);
    for(int i=1;i<=n;i++){
        cin >> vec[i];
    }
    init(1,1,n);
    int m;
    cin >> m ;
    int a,b,c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if(a==1)
            change(1,1,n,b,c);
        else
            cout << find(1,1,n,b,c)<<'\n';
    }
    
}