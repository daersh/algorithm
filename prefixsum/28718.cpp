#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n , m ;

    cin >> n >> m;
    int arr[n+1][m+1] ;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++)
            arr[i][j] = 0 ;  
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> arr[i][j] ;
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] ;
        }
    }
    int a;
    cin >> a;
    int ans = 0;
    for(int i = 1 ; i <= m-a+1 ; i++){
        // cout << i<< ' ';
        int v = arr[n][i+a-1]-arr[n][i-1];
        // cout << v<<'\n';
        ans = max(v,ans);
    }
    cout << ans;
}