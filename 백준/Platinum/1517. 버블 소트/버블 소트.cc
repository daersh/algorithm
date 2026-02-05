#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
using pii = pair<int,int>;
int n, a;
vector<pii> vec;
vector<int> seg;

void update(int loc, int s, int e, int st, int ed) {
    if (ed < s || e < st) return;
    if (st <= s && e <= ed){seg[loc]+=1; return;}
    int m = (s + e) / 2;
    update(loc * 2, s, m, st, ed);
    update(loc * 2 + 1, m + 1, e, st, ed);
}

int find(int loc, int s, int e, int idx) {
    if (idx < s || e < idx) return 0;
    if (s == e) return seg[loc]; 
    int m = (s + e) / 2;
    return seg[loc] + (idx <= m ? find(loc * 2, s, m, idx) : find(loc * 2 + 1, m + 1, e, idx));
}

bool compare(pii a, pii b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vec.resize(n);
    seg.resize(n*4);

    for (int i = 0; i < n; i++) {
        cin >> a;
        vec[i] = {a,i};
    }
    sort(vec.begin(), vec.end(),compare);

    long long result = 0;
    for(int i = 0; i < n; i++) {
        int idx = vec[i].second; 
        int found = find(1, 0, n - 1, idx);
        result += idx - i+ found;
        if (idx <= 0) continue;

        update(1, 0, n - 1, 0, idx - 1);
    }
    cout << result;
    return 0;
}