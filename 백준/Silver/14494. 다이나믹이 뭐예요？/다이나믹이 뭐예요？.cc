#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9+7;
int v[1010][1010]={0,};
int main(){
    int n, m;
    cin >> n >> m;
    v[1][1]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            v[i+1][j]=(v[i+1][j]+v[i][j])%INF;
            v[i+1][j+1]=(v[i+1][j+1]+v[i][j])%INF;
            v[i][j+1]=(v[i][j+1]+v[i][j])%INF;
        }

    cout << v[n][m];
}