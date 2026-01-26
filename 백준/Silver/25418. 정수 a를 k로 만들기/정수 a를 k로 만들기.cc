#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> dp(m+1,1e9);
    dp[n]=0;
    for(int i=n;i<=m;i++){
        if(i*2 <= m)
            dp[i*2]=min(dp[i]+1, dp[i*2]);
        if(i+1 <= m)
            dp[i+1]=min(dp[i]+1, dp[i+1]);
    }
    cout << dp[m];
}