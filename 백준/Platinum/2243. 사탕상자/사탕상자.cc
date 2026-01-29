#include <iostream>
#include <vector>

using namespace std;
vector<int> seg(4000001,0);

int update(int loc, int s, int e, int v, int count) {
    if (s == e) return seg[loc] += count;
    
    int m = (s+e) / 2;
    if (v <= m) update(loc * 2, s, m, v, count);
    else update(loc * 2 + 1, m + 1, e, v, count);
    
    return seg[loc] = seg[loc * 2] + seg[loc * 2 + 1];
}

int find(int loc, int s, int e, int k) {
    if (s==e) {
        seg[loc]--;
        return s;    
    }  

    int m = (s+e)/2;
    int idx;

    if (seg[loc * 2] >= k) 
        idx = find(loc * 2, s, m, k);
    else 
        idx = find(loc * 2 + 1, m + 1, e, k - seg[loc * 2]);

    seg[loc] = seg[loc * 2] + seg[loc * 2 + 1];

    return idx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int a,b,c;
    for(int i=0; i< n;i++){
        cin>> a;
        if(a==2){
            cin >> b>>c;
            update(1, 0,1000000,b,c);

        }else if(a==1){
            cin >> b;
            int removed = find(1, 0, 1000000, b);
            cout << removed<<'\n';
        }
    }

}