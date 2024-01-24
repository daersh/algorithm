
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
typedef pair<int,int> pii;

int arr[1000001];
int tree[4000001];

//tree
int make_tree(int loc, int l, int r){
    if(l==r) return tree[loc] = arr[l];
    int mid = (l+r)/2;
    return tree[loc]= min(make_tree(loc*2,l,mid), make_tree(loc*2+1 , mid+1 , r));
}

//구간합 구하기
int find(int loc,int l, int r, const int& b, const int& c){
    if(c<l || r < b){
        return 0;   //잘못된 경우 뻄
    }
    if( b<=l && r <=c){
        return tree[loc];
    }
    int mid = (l+r)/2;
    int x= find(loc*2,l,mid,b,c);
    int y= find(loc*2+1,mid+1,r,b,c);

    if(x==0){
        return y;
    }else if(y==0){
        return x;
    }else {
        return min(x ,y);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n>>m;
    for(int i=0; i<n;i++){
        cin >> arr[i];
    }
    make_tree(1,0,n-1);

    for(int i=0; i<m;i++){
        int b,c;
        cin >> b>>c;
        cout << find(1,0,n-1,b-1,c-1)<<'\n';
    }

}