#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int a[n+1];
    vector<int> dp(n+1, 0);
    for(int i=1;i<=n;i++) 
        cin >> a[i];
    dp[1] = true;
    for(int i=1;i<=n;i++){
        if(!dp[i]) continue;
        for(int j=i+1;j<=n;j++){
            int next = (j-i)*(1+ abs(a[i]-a[j]));
            if(next <=m)dp[j] = true;
        }
    }
    if(dp[n]) cout << "YES";
    else cout << "NO";
}