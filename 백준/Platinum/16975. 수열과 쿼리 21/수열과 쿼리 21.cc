#include <iostream>
#include <vector>

using namespace std;
int INF = 2000000000;
vector<long long> vec;
vector<long long> seg;

long long find(int loc, int start, int end, int x){
    // cout << loc <<' ' << start <<' ' << end <<' ' <<'\n';
    if(x>end || x<start)    return 0;
    if(start==end) {
        // cout << "found\n";
        return seg[loc];
    }
    long long sum=0;
    if(x>=start && x<=end){
        sum += seg[loc];
    }
    int mid = (start+end)/2;
    return sum += find(loc*2,start,mid,x)+find(loc*2+1,mid+1,end,x);
}

void change(int loc, int start, int end, int x, int y, int value){
    // cout << loc <<' ' << start <<' ' << end <<' ' <<'\n';
    if(x>end || y<start) return;
    if(x<=start && y >=end) {
        // cout << "found!\n";
        seg[loc] +=value;
        return;
    }
    int mid = (start+end)/2;
    change(loc*2, start, mid, x, y, value);
    change(loc*2+1, mid+1,end, x, y, value);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vec.resize(n+1);
    seg.resize(n*4);
    for (int i = 1; i <= n; i++)
        cin >> vec[i];
    // init(1,1,n);
    int m;
    cin >> m;
    int a,s,d,f;
    for (int i = 0; i < m; i++){
        cin >> a ;
        if(a==1){
            cin >>  s>> d>> f;
            change(1,1,n,s,d,f);
            // for (int j = 0; j < n*4; j++){
            //     cout << seg[j] <<' ';
            // }cout << '\n';
        }else{
            cin >> s;
            cout << vec[s]+find(1,1,n,s)<<'\n';
        }

    }
    
    
}