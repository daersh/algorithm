#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

typedef pair<int,int> pii;

int N,M;
priority_queue<pii, vector<pii>, greater<pii> > pque;


vector<pii> vec[200100];
int dist[1000];

void digkstra(int start){
    pque.push(make_pair(0,start));
    
    dist[start]=0;
    while(!pque.empty()){

        int distance= pque.top().first;
        int loc= pque.top().second;
        pque.pop();

        if(distance> dist[loc]){
            continue;
        }

        for(int i=0;i<vec[loc].size();i++)
        {

                int vec_dist= vec[loc][i].first;
                int vec_loc = vec[loc][i].second;
                
                //저장된 값보다 짧은 경로임을 확인했을 경우
                if(vec_dist+distance < dist[vec_loc])
                {
                    dist[vec_loc]= vec_dist+distance;
                    
                    pque.push(make_pair(dist[vec_loc],vec_loc));
                }
        }

    }
    return;
}


int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    int x,y,d;

    for(int i=0;i<M;i++){
        cin >> x >> y >> d;
        vec[x].push_back(make_pair(d,y));
        vec[y].push_back(make_pair(d,x)); 
    }   
    int a,b;
    cin >> a >> b;
    
    fill(&dist[0], &dist[1000], INF);
    digkstra(1);
    int s_a= dist[a];
    int s_b= dist[b];
    int cmp;

    fill(&dist[0], &dist[1000], INF);
    digkstra(a);
    int a_b = dist[b];
    int a_N = dist[N];
    
    fill(&dist[0], &dist[1000], INF);
    digkstra(b);
    int b_N = dist[N];

    // cout << "cmp: " << cmp << '\n';
    // cout << "     " << dist[a] + a_b + b_N <<'\n';
    // cout << "     " << dist[a] + a_b + a_N <<'\n';

    int cmp2 = s_a + a_b + b_N;
    int cmp3 = s_b + a_b + a_N;
    
    if(cmp2>cmp3){
        cmp = cmp3;
    }else{
        cmp = cmp2;
    }
    if(cmp >=INF || cmp<0)cout << -1;
    else cout <<cmp;
    
    


    return 0;
}

