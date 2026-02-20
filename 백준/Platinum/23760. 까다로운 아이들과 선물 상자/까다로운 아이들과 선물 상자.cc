#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 100010;
vector<int> vec(MAXN);
vector<int> children(MAXN);
vector<int> seg(MAXN*4);

int n, m;

int init(int loc, int s, int e){
    if(s==e) return seg[loc] = vec[s];
    int m = (s+e)/2;
    return seg[loc] = init(loc*2, s, m) + init(loc*2+1, m+1, e);
}

int find(int loc, int s, int e, int b){
    if(s==e) return s;
    int m = (s+e)/2;
    int r = seg[loc*2+1];
    if(b<=r) return find(loc*2+1, m+1, e, b);
    else return find(loc*2, s, m, b-r);
}

int update_m(int loc, int s, int e, int idx){
    if(idx<s || idx>e) return seg[loc];
    if(s==e) return seg[loc]=seg[loc]-1;
    int m = (s+e)/2;
    return seg[loc] = update_m(loc*2, s, m, idx) + update_m(loc*2+1, m+1, e, idx);
}

int update_p(int loc, int s, int e, int idx){
    if(idx<s || idx>e) return seg[loc];
    if(s==e) return seg[loc]=seg[loc]+1;
    int m = (s+e)/2;
    return seg[loc] = update_p(loc*2, s, m, idx) + update_p(loc*2+1, m+1, e, idx);
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        vec[a]++;
    }
    init(1,0,MAXN-1);
    for(int i=0; i<m; i++) cin >> children[i];
    for(int i=0; i<m;i++){
        int b;
        cin >> b;                   // 몇번째로 많은 거
        int wanted = children[i];   // 가져갈 개수
        int idx = find(1,0,MAXN-1,b);
        if(wanted > idx) {
            cout << "0\n";
            return 0;
        } else {
            update_m(1,0,MAXN-1,idx);
            update_p(1,0,MAXN-1,idx-wanted);
        }
    }
    cout << "1\n";
}