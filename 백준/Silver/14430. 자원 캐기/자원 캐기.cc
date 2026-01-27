#include <iostream>
#include <vector>

using namespace std;
int v[310][310];
int dp[310][310]={0,};

int main(){
    int n , m;
    cin >> n >> m;
    for (int i = 1; i < n+1; i++)for (int j = 1; j < m+1; j++) cin >> v[i][j];
    dp[1][1]=v[1][1];
    for (int i = 1; i < n+1; i++) for (int j = 1; j < m+1; j++){
            dp[i+1][j] = max(dp[i+1][j], v[i+1][j]+dp[i][j]);
            dp[i][j+1] = max(dp[i][j+1], v[i][j+1]+dp[i][j]);
        }
    cout << dp[n][m];
}