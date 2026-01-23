#include <iostream>
#include <vector>
using namespace std;

typedef pair<pair<int, int>, int> ppiii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ppiii> v(n+1);
    int a,b,c;
    for (int i = 1; i <= n; i++){
        cin >> a >> b >> c;
        v[i] = {{a, b}, c};
    }

    int dp[n+1];
    dp[0]=0;
    dp[1]=v[1].second;
    dp[2]=v[2].second;
    for(int i=3;i<=n;i++)dp[i] = max(dp[i-2]+v[i].second, dp[i-3]+v[i].second);

    cout << max(dp[n], dp[n-1]);
}