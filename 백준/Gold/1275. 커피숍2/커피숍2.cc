#include <iostream>
#include <vector>
using namespace std;

vector<long long> vec;
vector<long long> seg;

long long init(long long loc, long long start, long long end){
    if(start == end)
        return seg[loc]= vec[start];
    long long mid = (start+end)/2;
    long long l = init(loc*2, start, mid);
    long long r = init(loc*2+1, mid+1, end);
    
    seg[loc]= l+r;
    // cout << "seg["<<loc<<"]: " <<seg[loc] <<'\n';
    return seg[loc];
}

long long find(long long loc, long long start, long long end, long long x, long long y){
    if(x>end || y<start) return 0;

    if(x <= start && end <= y)
        return seg[loc];

    long long mid = (start+end)/2;
    long long l = find(loc*2, start, mid, x,y) ;
    long long r = find(loc*2+1, mid+1, end, x,y) ;
    return l+r;
}
long long change(long long loc, long long start, long long end, long long c, long long v){
    if(c< start || c >end){
        return seg[loc];
    }
    if(start ==end){
        vec[start]= v;
        return seg[loc]= v;
    }
    long long mid = (start+end)/2;
    long long l = change(loc*2, start, mid, c, v);
    long long r = change(loc*2+1, mid+1, end, c, v);
    return seg[loc]= l+r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,m;
    cin >> n >> m;
    vec.resize(n+1);
    seg.resize(n*4);
    for(long long i=1; i<= n; i++){
        cin >> vec[i];
    }
    init(1,1,n);
    // for(long long i=0; i<n*4;i++){
    //     cout << seg[i] << ' ';
    // }cout << '\n';
    for(long long i=0; i<m;i++){
        long long x,y,a,b;
        cin >> x>>y >>a >>b;
        if(x>y)
            cout << find(1,1,n,y,x)<<'\n';
        else 
            cout << find(1,1,n,x,y)<<'\n';

        change(1,1,n,a,b);
    }
}