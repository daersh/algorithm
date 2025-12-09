#include <iostream>
#include <vector>
using namespace std;

vector<long long > vec;
vector<long long> seg;
long long init(int loc, int start, int end){
    if(start==end)
        return seg[loc]= vec[start];
    int mid= (start+end)/2;
    long long l= init(loc*2,start,mid);
    long long r= init(loc*2+1,mid+1,end);
    return seg[loc]= l+r;
}

long long find(int loc, int start, int end, int x, int y){
    if(x>end || y< start) return 0;
    if(x <= start && end <= y)
        return seg[loc];
    int mid = (start+end)/2;
    long long l = find(loc*2, start, mid, x,y);
    long long r = find(loc*2+1, mid+1,end, x, y);
    return l+r;
}

long long change(int loc, int start, int end, int x, int y){
    if(x<start || x>end)
        return seg[loc];
    if(start==end){
        vec[start]=y;
        return seg[loc]= y;
    }
    int mid = (start+end)/2;
    long long l = change(loc*2, start, mid, x,y);
    long long r = change(loc*2+1, mid+1, end, x,y);
    return seg[loc] = l+r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m ;
    vec.resize(n+1);
    seg.resize(n*4);
    
    init(1,1,n);
    int a,b,c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if(a==0){
            if(b<=c)
                cout << find(1,1,n,b,c) <<'\n';
            else    
                cout << find(1,1,n,c,b)<<'\n';
        }
        else if(a==1)
            change(1,1,n,b,c);
    }
    
}