#include <iostream>
#include <vector>
using namespace std;

int asdf = 1000000007;

vector<int> vec;
vector<long long> seg;
int n,m,k;

long long init(long long loc, long long start, long long end){
    if(start==end) {
          seg[loc]=vec[start];
          return seg[loc];
    }
    long long mid = (start+end)/2;
    long long l = init(loc*2, start, mid )%asdf;
    long long r= init(loc*2+1, mid+1, end)%asdf;
    seg[loc] = (l*r)%asdf;
    // cout << "       "<<seg[loc]<< '\n';
    return seg[loc];
}

long long find(long long loc, long long start, long long end, long long left, long long right){
    if(left>end || right < start){
        return 1;
    }
    if(left <= start && end <=right)
        return seg[loc];
    long long mid= (start + end)/ 2;
    long long l = find(loc*2, start, mid, left, right)%asdf;
    long long r = find(loc*2+1, mid+1, end,left,right)%asdf;
    return (l*r)%asdf;
}

void change(long long loc, long long start, long long end, long long target, long long value){
    if(target < start || target > end) return;
    if(start==end) {
        seg[loc]= value;
        return;
    }
    long long mid = (start +end)/2;
    change(loc*2, start, mid, target, value);
    change(loc*2+1, mid+1, end, target, value);
    seg[loc] = (seg[loc*2] *seg[loc*2+1])%asdf;
}

int  main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    vec.resize(n+1);
    seg.resize(n*4);

    for(int i=1;i<=n;i++)
        cin >> vec[i];
    
    init(1,1,n);

    // for(int i=1; i<seg.size();i++)
        // cout << seg[i]<< '\n';
    
    int x,y,z;
    for (int i = 0; i < m+k; i++)
    {
        cin >> x>> y>> z;
        if(x==1){
            // cout <<" 구간곱 바꾸기 \n";
            change (1,1,n,y,z);
        }
        else {
            cout<< find(1,1,n,y,z)<<'\n';
        }
    }
    


}