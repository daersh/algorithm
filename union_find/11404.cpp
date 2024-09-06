#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1e9; 
vector<pair<int, int> > graph[101];
int dist[101][101];

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


    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <=N; j++) {
            if(dist[i][j]==INF)
                dist[i][j]= 0;
            cout <<  dist[i][j] <<' ';
        }cout <<'\n';
    }

    
    return 0;
}