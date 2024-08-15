
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
int n, m,h;
long long dist[100000];

bool bf(int start, vector<Node> edges){
    dist[start] =0;
    

    for(int i =0 ; i < n; i ++){


        for(int j=0;j<edges.size();j++) {
            int cur_loc = edges[j].a;
            int next_loc = edges[j].b;
            int cost = edges[j].c;

            if(dist[next_loc]> dist[cur_loc]+cost){
                dist[next_loc] = dist[cur_loc]+cost;
                if(i==n-1)
                    return true; 
            }
        }
    }
    return false;
}

int main(){
    int T;
    cin >> T;
    for(int t=0; t<T;t++){
        cin >> n >> m >> h; //노드, 간선, 웜홀 개수 입력
        vector<Node> edges;
        
        int a,b,c;
        for(int i =0 ; i < m; i++){
            cin >> a >> b>> c;
            // a에서 b 가는데 c비용이 든다.
            edges.push_back(Node(a,b,c));
            edges.push_back(Node(b,a,c));
        }

        for(int i = 0 ; i < h; i++){
            cin >> a >> b>> c;
            // a에서 b 가는데 c비용이 든다.
            edges.push_back(Node(a,b,-c));
        }

        fill(&dist[0],&dist[n+1],INF);

        // bellman-ford 알고리즘 수행
        bool result = bf(1,edges);

        if(!result){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }
    
}