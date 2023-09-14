#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
typedef pair<int,int> pii;

int N, M;
int d[102];

int T;
int t;
int K;

int sum[102];

void digkstra(int start, vector<pii> vec[]){
    priority_queue<pii, vector<pii>, greater<pii> > pque;

    pque.push(make_pair( 0,start) );
    d[start]=0;
    while(!pque.empty()){
        int dist= pque.top().first;
        int loc = pque.top().second;
        pque.pop();
        if(dist>d[loc]){
            continue;
        }

        for(int i=0;i<vec[loc].size(); i++){
            int vec_dist = vec[loc][i].first;
            int vec_loc = vec[loc][i].second;

            if(dist + vec_dist < d[vec_loc]){
                d[vec_loc] = dist+vec_dist;
                pque.push(make_pair(d[vec_loc], vec_loc ) );
            }
        }
    }


    for(int i=1;i<=N;i++){
        sum[i]+=d[i];
    }
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    
    //test case insert
    cin >> T;

    for(t=1;t<=T;t++){
        //insert N, K;
        cin >> N >> M;
        int x, y, z;
        fill(&sum[0],&sum[102],0);
        vector<pii> vec[N+1];
        
        for(int i=0;i<M;i++){
            cin >> x >> y >> z;
            vec[x].push_back(make_pair(z,y));
            vec[y].push_back(make_pair(z,x));
        }
        //cout << "K insert: ";
        cin >> K;

        int room[K];
        for(int i=0;i<K;i++){
            //cout << "room insert: ";
            fill(&d[0],&d[102],INF);
            cin >> room[i];
            digkstra(room[i], vec);
        }
        int result=INF;
        int result_loc;
        for(int i=1;i<=N;i++){
            if(sum[i]<result){
                result=sum[i];
                result_loc = i;
            }
        }
        cout << result_loc << '\n';

    }
    return 0;
}

