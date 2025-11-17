#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        int k, n;
        cin >> k >> n;
        int arr[k+1][n+1];
        for(int i=1;i<=n;i++){
            arr[0][i]=i;
        }
        for(int i=1;i<=k;i++){
            arr[i][0]=0;
        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
            }
        }
        cout << arr[k][n] << '\n';
    }
}