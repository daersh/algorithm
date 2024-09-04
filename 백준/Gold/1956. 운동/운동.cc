#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1e9; 
vector<pair<int, int> > graph[402];
int dist[402][402];

int main()
{
    int N, K;
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < K; i++) {
        int x, y,z;
        cin >> x >> y>> z;
        dist[x][y]= min(dist[x][y],z);
    }


    //floyd warshall
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) {
                    dist[i][j] = 0;
                    continue;
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }


    int result = INF;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <=N; j++) {
            if(dist[i][j]==INF || i==j)
                continue;
            result = min(result, dist[i][j]+dist[j][i]);
        }
    }
    if(result ==INF)
        result= -1;
    cout << result;
    return 0;
}