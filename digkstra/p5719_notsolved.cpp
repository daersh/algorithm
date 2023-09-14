#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
typedef pair<int,int> pii;

//정점(장소), 간선(도로)
int N, M;
//시작점, 도착지
int S, D;
//거리 
int d[502];

vector<pii> vec[502];

//최단경로 저장을 어ㄸ허게
    //역추적?
    //역추적해서 해당 벡터들 전부 INF로 만들어서 못지나가게 만들기?
int arr[502];

void find_road(){
    
    int x = arr[D];
    
}

void digkstra(int start){
    priority_queue <pii, vector<pii>, greater<pii> >pque;
    pque.push(make_pair(0,start));
    d[start]=0;

    while(!pque.empty()){
        int dist = pque.top().first;
        int loc = pque.top().second;
        pque.pop();
        
        if(dist > d[loc]){
            continue;
        }
        if(loc==D){
            continue;
        }
        for(int i=0;i<vec[loc].size();i++){
            int vec_dist = vec[loc][i].first;
            int vec_loc = vec[loc][i].second;

            if(vec_dist+dist< d[vec_loc]){
                arr[vec_loc]= loc;
                d[vec_loc] = vec_dist+dist;    
                pque.push(make_pair(d[vec_loc], vec_loc));
            }

            
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    while(1){
        //장소, 도로 insert
        cin >> N >> M;
        fill(&d[0],&d[502],INF);
        fill(&arr[0],&arr[502],0);
        for(int i=0;i<502;i++){
            vec[i].clear();
        }

        if(N==0 && M==0){
            return 0;
        }
        //출발지, 도착지 insert
        cin >> S >> D;

        int x,y,z;
        for(int i=0;i<M;i++){
            cin >> x >> y >> z;
            vec[x].push_back(make_pair(z,y));
            //d를 가리키는경우 역으로도 받아보기
            if(y==D){
                vec[y].push_back(make_pair(z,x));
            }
        }

        digkstra(S);
        cout << "목적지까지의 최단거리: "<<d[D] << '\n';
        find_road();
        //최단 경로 지나는 도로 다 제거해야함!


    }

}
