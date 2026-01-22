#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n+1];
    int dp[n+1];
    dp[0] = 0;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        dp[i] = a[i];
    };

    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
            dp[i] = min(dp[i], dp[i-j] + a[j]);
    cout << dp[n];
}