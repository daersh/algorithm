#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
typedef pair<int, int> pii;
const int INF = 1e9;

int main(){
    int n , m;

    cin >> n >> m;
    vector<pii> vec[n];
    int dist[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dist[i][j] = INF;
        }
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        // vec[x].push_back(make_pair(y,1));
        dist[x][y]=1;
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j < vec[i].size(); j++) {
    //         int loc = vec[i][j].first;
    //         int d = vec[i][j].second;
    //         dist[i][loc] = d;
    //     }
    // }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j =1; j<=n;j++){
                if(i==j){
                    dist[i][j] = 0;
                    continue;
                }

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int cnt =0;
    for(int i=1;i<=n;i++){
        int found = 0;
        for(int j=1;j<=n;j++){
            if(dist[i][j]==INF && dist[j][i]==INF){
                found++;
            }
        }
        cout << found << '\n';
    }
    // cout << cnt;

}