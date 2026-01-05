#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> saram(n+1);
    vector<int> happy(n+1);
    vector<int> dp(101);
    int x, y, z;
    for(int i=0;i<n;i++) cin >> saram[i];
    for(int i=0;i<n;i++) cin >> happy[i];
    
    for(int i=0; i<n;i++){
        for(int j=100;j>saram[i];j--){
            dp[j]= max(dp[j], dp[j-saram[i]]+happy[i]);
        }
    }
    
    // for(int j=0;j<=100;j++)
    //     cout << dp[j] <<' ';
    cout <<dp[100];
}