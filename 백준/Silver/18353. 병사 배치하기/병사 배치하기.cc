#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    for(int i = 1; i <= n; i++) 
        cin >> arr[i];
    
    vector<int> dp(n + 1, 0);
    dp[1] = arr[1];
    int dp_index = 1;
    for(int i=2;i<=n;i++){
        if(arr[i]< dp[dp_index]){
            // cout << arr[i] << " ";
            dp[++dp_index] = arr[i];
        }else {
            for(int j=1;j<=dp_index;j++){
                if(arr[i] >= dp[j]){
                    dp[j] = arr[i];
                    break;
                }
            }
        }
    }
    // for(int i=1;i<=dp_index;i++){
    //     cout << dp[i] << " ";
    // }cout << "\n";
    cout << n-dp_index << "\n";

}