#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1e9; 
vector<pair<int, int> > graph[101];
int dist[101][101];
int sum[101];
int uArr[101];


int find_parent(int x)
{
    if (uArr[x] == x) return x;
    else return uArr[x] = find_parent(uArr[x]);
}


void union_parent(int x, int y)
{
    x = find_parent(x);
    y = find_parent(y);
    if (x != y) {
        if (sum[x] <= sum[y]) uArr[y] = x;
        else uArr[x] = y;
    }
}

int main()
{
    int N, K;
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) uArr[i] = i;

    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(make_pair(y, 1));
        graph[y].push_back(make_pair(x, 1));
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int loc = graph[i][j].first;
            int d = graph[i][j].second;
            dist[i][loc] = d;
        }
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
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] == INF) continue;
            // 한 노드에서 가장 큰 값 찾기
            sum[i] = max(sum[i], dist[i][j]); 
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            union_parent(i, graph[i][j].first);
        }
    }

    set<int> result;
    for (int i = 1; i <= N; i++) result.insert(find_parent(i));
    
    cout << result.size() << "\n";
    for (auto& it : result) cout << it << "\n";

    return 0;
}