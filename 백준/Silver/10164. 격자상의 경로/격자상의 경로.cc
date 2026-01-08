#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<long long>> vec(n+2, vector<long long>(m+2, 0));
    pair<int, int> one = {(k-1)/m+1, (k-1)% m +1};

    vec[1][1] = 1;
    for(int i=1; i<= n; i++){
        for(int j=1; j<= m; j++){
            vec[i+1][j] +=vec[i][j];
            vec[i][j+1] +=vec[i][j];
        }
    }
    if(k ==0){
        cout << vec[n][m];
        return 0;
    }
    cout << vec[one.first][one.second] * vec[n-one.first+1][m-one.second+1] << "\n";

}
