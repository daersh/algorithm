#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii= pair<int,int>;

int INF= 2e9;
int n,m;
vector<int> vec;
vector<pii> seg;

pii init(int loc, int start, int end){
    if( start==end) 
        return seg[loc] = {vec[start],vec[start]};
    int mid = (start+end)/2;
    pii left = init(loc *2, start, mid);
    pii right =init(loc *2 +1, mid+1, end);
    seg[loc]= {min(left.first,right.first), max(left.second, right.second)};
    return seg[loc];
}

pii find(int loc, int start, int end, int left, int right){
    if(left >end || right < start)
        return {INF,0};
    if(left <= start && end <= right)
        return seg[loc];
    int mid= (start + end)/ 2;
    pii left_v = find(loc*2, start, mid, left, right);
    pii right_v = find(loc*2+1, mid+1, end,left,right);
    return {min(left_v.first,right_v.first), max(left_v.second, right_v.second)};
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vec.resize(n+1);
    seg.resize(n*4);
    for (int i = 1; i <= n; i++)
        cin >> vec[i];
    init(1,1,n);
    // for(int i=0; i<seg.size();i++){
    //     cout << "i: "<< i << ", seg: " << seg[i].first <<','<< seg[i].second<<'\n';
    // }
    int a,b;
    for (int i = 0; i < m; i++){
        cin >> a>>b;
        pii result = find(1,1,n,a,b);
        cout << result.first << ' ' << result.second <<'\n';
    }
    
    
}





/*                     5_100
            30_100              81_5
      30_100.            20_52      81_5
  30_75  38_100      50_51   20_52 
75 30   100 38      50 51   52 20    81 5

*/