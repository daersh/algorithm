
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<long long,long long> pii;

long long arr[1000001];
long long tree[4000001];

//tree
long long make_tree(long long loc, long long l, long long r){
    if(l==r) return tree[loc] = arr[l];
    long long mid = (l+r)/2;
    return tree[loc]= make_tree(loc*2,l,mid) + make_tree(loc*2+1 , mid+1 , r);
}

//const long long& : 메모리를 아낄 수 있고, 변경을 방지함
void update_tree(long long loc, long long l, long long r, const long long& newIndex, const long long& newValue){
    if(l==r){
        tree[loc] = newValue;
        return;
    }
    long long mid= (l+r)/2;

    if(l <=newIndex && newIndex <=mid ){
        update_tree(loc*2,l,mid,newIndex,newValue);
    }else{
        update_tree(loc*2+1,mid+1,r,newIndex,newValue);
    }
    tree[loc]= tree[loc*2]+ tree[loc*2+1];
    return;
}

//구간합 구하기
long long sum_tree(long long loc,long long l, long long r, const long long& b, const long long& c){
    if(c<l || r < b){
        return 0;   //잘못된 경우 뻄
    }
    if( b<=l && r <=c){
        return tree[loc];
    }
    long long mid = (l+r)/2;
    return sum_tree(loc*2,l,mid,b,c)+ sum_tree(loc*2+1,mid+1,r,b,c);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long n,m,k;
    cin >> n>>m>>k;
    for(long long i=0; i<n;i++){
        cin >> arr[i];
    }
    make_tree(1,0,n-1);

    for(long long i=0; i<m+k;i++){
        long long a,b,c;
        cin >> a>>b>>c;
        
        if(a==1){
            update_tree(1,0,n-1,b-1,c);
        }else{
            cout << sum_tree(1,0,n-1,b-1,c-1)<<"\n";
        }
    }

}