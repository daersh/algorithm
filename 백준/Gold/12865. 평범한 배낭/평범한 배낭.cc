#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
using pii= pair<int,int>;

vector<int> dp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m; 
    cin >> n >> m;
    dp.resize(m+1);
    int x,y;
    for(int i=0;i<n;i++){
        cin >> x >>y;
        for(int j=m;j>=x;j--) dp[j] = max(dp[j], dp[j-x]+y);
    }
    cout << dp[m];
}