#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int > pii;
const int INF = 1e9;

int d[21];
vector<pii> vec[21];
//test case 수
int T;
//N: 관계 개수   M: 정치인 수
int N, M;
//역추적 하기 위함
int arr[21];
int t;


void digkstra(int start){

    priority_queue <pii, vector<pii>, greater<pii> > pque;

    pque.push(make_pair(0,start));
    d[0]=0;
    while (!pque.empty())
    {
        int dist = pque.top().first;
        int loc = pque.top().second;
        pque.pop();

        arr[start] = start;

        if(dist> d[loc] ){
            continue;
        }

        for(int i=0;i<vec[loc].size();i++){
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

    // while(!pque.empty()){
    //     int dist= pque.top().first;
    //     int loc = pque.top().second;
    //     pque.pop();

    //     if(dist > d[loc]){
    //         continue;
    //     }

    //     for(int i=0; i<vec[loc].size(); i++){
    //         int vec_dist= vec[loc][i].first;
    //         int vec_loc = vec[loc][i].second;

    //         if(dist+ vec_dist < d[vec_loc]){
    //             //역추적
    //             arr[vec_loc]= loc;
    //             //거리 갱신
    //             d[vec_loc]= dist+ vec_dist;
    //             pque.push(make_pair(d[loc], vec_loc));
    //         }
    //     }
    // }
    
    //출력
    cout << "Case #" <<t+1 << ": ";
    if(d[M-1] >= INF){
        cout << -1 << '\n';
        return;
    }

    int asdf= M-1;
    vector<int> vect;

    vect.push_back(asdf);
    while(asdf!=0){
        vect.push_back(arr[asdf]);
        asdf=arr[asdf];
    }
    while (!vect.empty())
    {
        cout << vect.back() << ' ';
        vect.pop_back();
    }
    cout << '\n';

}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for(t=0;t<T;t++){
        cin >> N >> M;
        int i , x ,y, z;

        fill(&d[0], &d[21], INF);
        fill(&arr[0], &arr[21],0);
        for(int i=0;i<21;i++){
            vec[i].clear();
        }

        for(i=0;i<N;i++){
            cin >> x >> y >> z;
            vec[x].push_back(make_pair(z,y));
            vec[y].push_back(make_pair(z,x));
        }
        digkstra(0);
    }

}