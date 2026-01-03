#include <iostream>
#include <vector> 
#include <queue>
using namespace std;
using ll= long long;
using asdf= pair<ll,pair<int,bool> >;
int T, n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T>0){
        T--;
        cin >> n;
        vector<vector<int> > inputs(2, vector<int>(n));
        vector<vector<int> > dp(2, vector<int>(n+1,0));
        for(int i=0; i < 2; i++)
            for(int j=0; j < n; j++)
                cin >> inputs[i][j];
        dp[0][0] = inputs[0][0];
        dp[1][0] = inputs[1][0];
        if(n>=2){
            dp[0][1] = dp[1][0] + inputs[0][1];
            dp[1][1] = dp[0][0] + inputs[1][1];
        }
        for(int i=2;i<n;i++){
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + inputs[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + inputs[1][i];
        }
        cout << max(dp[0][n-1],dp[1][n-1])<<'\n';
    }
}