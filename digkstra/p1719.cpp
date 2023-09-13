#include <bits/stdc++.h>
using namespace std;
//정점, 간선
int N, M;
#define INF 1e9
typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<pii> > pque;
vector <pii> vec[210];

int d[210];

pii result[210];
int arr[210];
//아니면 역추적으로?????????????????


int find_next(int x, int y){
    int a;
    int past_val;
    while(y!=x){
        a = arr[y];
        past_val=y;
        y=a;
    }
    return past_val;
}

void digkstra(int start){
    int i,j;

    while (!pque.empty())
    {
        int dist = pque.top().first;
        int loc = pque.top().second;
        pque.pop();

        arr[start] = start;

        if(dist> d[loc] ){
            continue;
        }

        for(i=0;i<vec[loc].size();i++){
            int vec_dist = vec[loc][i].first;
            int vec_loc = vec[loc][i].second;
            //기본 위치까지의 거리 + 다음 이동할 거리가 기존 d[] 보다 작으면 저장
            if(dist + vec_dist < d[vec_loc]){
                //다음 위치는 이전 위치를 가리키도록함
                arr[vec_loc] = loc;
                d[vec_loc] = dist+ vec_dist;
                pque.push(make_pair(d[vec_loc],vec_loc));
            }
        }
    }
}


int main(){
    cin >> N >> M;
    int i,j;
    int a,b,c;

    for(i=1 ; i<=M;i++ ){
        cin >> a >> b >>c ;
        vec[a].push_back(make_pair(c,b));
        vec[b].push_back(make_pair(c,a));
    }

    for(i=1;i<=N;i++){
        fill(&d[0], &d[210], INF);
        fill(&arr[0],&arr[210],-1);    
            
        pque.push(make_pair(0,i));
        digkstra(i);
        for(j=1;j<=N;j++){
            if(i==j){
                cout << "- ";
                continue;
            }
            cout << find_next(i,j) <<' ';
        }
        cout << '\n';
    }

    

}