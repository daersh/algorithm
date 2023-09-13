#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

typedef pair<int,int> pii;

//우선순위 큐는 디폴트가 큰걸 위로 하기 때문에 
//아래처럼 하면 작은게 우선순위로 들어감
priority_queue<pii, vector<pii>, greater<pii> > pque;
vector<pii> vec[200100];
int N,M, start_point;
int d [200100];
//

int dist;
int loc;
void digkstra(int start){

    pque.push(make_pair(0,start));
    d[start]=0;

    while (!pque.empty())
    {
        dist= pque.top().first;
        loc= pque.top().second;
        pque.pop();
        if(d[loc]<dist){
            continue;
        }

        for(int i=0;i< vec[loc].size();i++){
            int next_val = vec[loc][i].first;
            int next_loc = vec[loc][i].second;

            //방문한 노드에서 연결된 노드들의 거리가 테이블 d과 비교했을 시 더 작으면 저장 
            if( next_val + dist < d[next_loc ]){
                //cout << "갱신 발생: " << next_loc<<"의 값:" << next_val << '\n';
                d[next_loc]= next_val + dist;
                pque.push(make_pair( d[next_loc], next_loc));
            }
        }
    }
    

}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M ;
    cin >> start_point;
    int x,y,z;
    for(int i=0;i<M;i++){
        cin >> x >> y >> z;
        vec[x].push_back(make_pair(z,y));
        vec[y].push_back(make_pair(z,x));
    }
    fill(&d[0],&d[200100],INF);

    digkstra(start_point);

    for(int i=1;i<=N;i++){
        if(d[i]==INF){
            cout << "INF\n";
            continue;
        }
        cout << d[i] << '\n';
    }
    return 0;
}

