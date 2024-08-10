// 간선의 비용이 0 또는 음수인 경우에 대한 최단 거리를 구하기 위한 알고리즘
// 다익스트라 사용 시
    // 다익스트라인 경우에도 0이나 음수인 경우에도 최단 거리를 계산할 수는 있다.
    // 하지만 음수 간선의 순환이 포함되면 음의 무한인 노드가 발생할 수 있다.
    // 이러한 이유로 Bellman-Ford algorithm을 사용해야 한다.
// 시간복잡도: O(VE) 정점 갯수 * 간선 갯수 - 다익스트라보다는 느리다.

// Bellman-Ford
// 1. 출발 노드 설정
// 2. 최단 거리 테이블ㅇ르 초기화
// 3. 다음 과정을 N-1 번 반복
    // 1. 전체 간선 E개를 하나씩 확인
    // 2. 각 간선을 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리 테이블을 갱신
// 만약 음수 간선 순환을 확인하고 싶다면 3번의 과정 한 번 더 수행
    // 한번 더 수행 시 최단 거리 테이블이 갱신된다면 음수 간선 순환이 존재한다는 것을 알 수 있다.

// 다익스트라 
    // 매번 방문하지 않은 노드 중 최단거리가 가장 짧은 노드만 선택
    // 음수 간선이 없어야 최적의 해를 구할 수 있다.
// 벨만포드
    // 매번 모든 간선을 전부 확인
    // 다익스트라보다 오래 걸리지만 음수 간선 처리 가능

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

struct Node {
    int a;
    int b;
    int c;
    Node(int x, int y, int z) : a(x), b(y), c(z) {};
};

const int INF = 1e9;
int n, m;
vector<Node> edges;
long long dist[100000];

bool bf(int start){
    dist[start] =0;
    
    // 1. 전체 n번의 라운드 반복
    for(int i =0 ; i < n; i ++){

        // 2. 매 반복마다 모든 간선 확인
        for(int j=0;j<m;j++) {

            int cur_loc = edges[j].a;
            int next_loc = edges[j].b;
            int cost = edges[j].c;

            // 현재 간선을 거쳐 다른 노드로 이동하는 거리가 더 짧은 경우 
            // 거리 갱신
            if(dist[cur_loc]!=INF && dist[next_loc]> dist[cur_loc]+cost){
                dist[next_loc] = dist[cur_loc]+cost;
                // n번째 라운드에서도 값이 갱신된다면 음수 순환이 존재한다.
                if(i==n-1){
                    return true;
                }
            }

        }
    }
    return false; // 음수 순환이 없다는 것
}

int main(){
    cin >> n >> m; //노드, 간선 입력
    int a,b,c;
    for(int i =0 ; i < m; i++){
        cin >> a >> b>> c;
        // a에서 b 가는데 c비용이 든다.
        edges.push_back(Node(a,b,c));
    }
    fill(&dist[0],&dist[n+1],INF);

    // bellman-ford 알고리즘 수행
    bool result = bf(1);
    
    // true이면 음수 순환이 존재하므로 -1 리턴
    if(result){
        cout << -1;
        return 0;
    }

    // 1번 노드를 제외한 다른 모든 노드로 가기 위한 최단 거리 출력
    for(int i =2 ; i< n+1; i++){
        cout << ((dist[i]==INF) ? -1 : dist[i] ) << '\n';
    }
    
}