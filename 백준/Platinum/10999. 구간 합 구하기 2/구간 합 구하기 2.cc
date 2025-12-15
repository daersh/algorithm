#include <iostream>
#include <vector>

using namespace std;

vector<long long> vec;
vector<long long> seg;
vector<long long> lazy;

long long init(int loc, int start, int end){
    if(start==end) return seg[loc]= vec[start];

    int mid= (start+end)/2;
    return seg[loc]= init(loc*2, start, mid)+ init(loc*2+1, mid+1, end);
}

void lazy_update(int loc, int start, int end){
    if(lazy[loc]!=0){
        seg[loc]+= (end-start+1)* lazy[loc];
        if(start!=end){
            lazy[loc*2]+= lazy[loc];
            lazy[loc*2+1]+= lazy[loc];
        }
        lazy[loc]=0;
    }
}

long long find(int loc, int start, int end, int x, int y){
    lazy_update(loc, start, end);
    if(x>end || y<start) return 0;
    if(x<=start && end<=y) 
        return seg[loc];
    
    int mid= (start+end)/2;
    return find(loc*2, start, mid, x, y)+ find(loc*2+1, mid+1, end, x, y);
}

long long change(int loc, int start, int end, int x, int y,long long val){
    lazy_update(loc, start, end);
    if(y<start || x>end) 
    return seg[loc];
    if(x<=start && end<=y) {
        // seg[loc]+= (end-start+1)* val;
        lazy[loc]+= val;
        lazy_update(loc, start, end);
        return seg[loc];
    }
    
    int mid= (start+end)/2;
    seg[loc]= change(loc*2, start, mid, x,y, val) + change(loc*2+1, mid+1, end, x,y, val);
    return seg[loc];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n , m, k;
    cin >> n >> m >> k;
    vec.resize(n+1);
    seg.resize(n*4);
    lazy.resize(n*4);

    for(int i=1; i<= n;i++){
        cin >> vec[i];
    }
    init(1,1,n);
    // for (int i = 0; i < n*4; i++)cout << seg[i] << " ";cout << "\n";
    
    for(int i=0;i<m+k;i++){
        long long a,b,c,d;
        cin >> a >> b >> c;
        if(a==1){
            cin >> d;
            change(1,1,n,b,c,d);
            // for (int i = 0; i < n*4; i++)cout << seg[i] << " ";cout << "\n";
        }else{
            cout << find(1,1,n,b,c) << "\n";
        }
    }
}