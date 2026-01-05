#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int INF = 1e9;
typedef pair<int,int > pii;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m ;
    cin >> n >> m;
    int x,y,z;
    vector<vector<pii>> input;
    input.resize(m+1);
    vector<int> dp(1000000,0);
    for(int i=0;i<=m;i++)
        dp[i]=i;
    for(int i=0; i< n; i++){
        cin >> x >> y >> z ;
        input[x].push_back({y,z});
    }
    
    for(int i=0;i<=m;i++){
        if(i-1>=0)
            dp[i]=min(dp[i], dp[i-1]+1);
        for(int j=0; j<input[i].size();j++){
            x= input[i][j].first;
            y= input[i][j].second;
            dp[x]=min(dp[x], dp[i]+y);
        }
        
    }
    cout << dp[m] <<' ';

}