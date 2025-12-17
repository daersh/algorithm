#include <iostream>
#include <vector>

using namespace std;

vector<long long> vec;
vector<long long> vec2;
vector<long long> seg;


void change(int l, int s, int e, int x, int y, long long v){
    if(x > e || y < s) return;
    if(x <= s && e <= y) {
        seg[l] += v;
        return;
    }
    int m = (s + e) / 2;
    change(l * 2, s, m, x, y, v);
    change(l * 2 + 1, m + 1, e, x, y, v);
}

long long find(int l, int s, int e, int x){
    if(x < s || x > e) return 0;
    if(s == e) return seg[l];
    int m = (s + e) / 2;
    return seg[l] + (x <= m ? find(l * 2, s, m, x) : find(l * 2 + 1, m + 1, e, x));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >>m;
    vec.resize(n+1);
    vec2.resize(n+1);
    seg.resize(n*4);
    long long past=1;
    int x;
    for(int i=1;i<=n;i++){
        cin >> x;
        vec[i]=past;
        past+=x;
        vec2[i]=x;
    }
    // for(int i=1;i<=n;i++)cout << vec[i]<<' '; cout <<'\n';
        
    long long a;
    for(int i=1;i<=m;i++){
        cin >> a;  
        cout << vec[a]-find(1,1,n,a)<<'\n';
        change(1,1,n,a+1,n, vec2[a] );
        // for (int j =1; j < n*4; j++) cout << seg[j]<<' ';cout <<'\n';
    }
    
}

// 1
// 22
// 333 
// 4444
// 55555