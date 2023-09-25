#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

const int INF =1e9;

using namespace std;
typedef pair<int,int > pii;
int N, M;
vector<pii> vec[100010];
int d[100010];

int x,y,z;

void digkstra(int start){
    priority_queue<pii, vector<pii>,greater<pii> >pque;
    d[start]=0;
    pque.push(make_pair(0,start));
    while (!pque.empty())
    {
        int dist= pque.top().first;
        int loc = pque.top().second;

        pque.pop();

        if(dist>d[loc]){
            continue;
        }
        for(int i=0;i<vec[loc].size();i++){
            int vdist=vec[loc][i].first;
            int vloc=vec[loc][i].second;
            if(vdist+dist<d[vloc] ){
                d[vloc]=vdist+dist;
                pque.push(make_pair(d[vloc],vloc));
            }
        }
    }
    
}

void digkstra2(int start){
    priority_queue<pii, vector<pii>,greater<pii> >pque;
    d[start]=0;
    pque.push(make_pair(0,start));
    while (!pque.empty())
    {
        int dist= pque.top().first;
        int loc = pque.top().second;

        pque.pop();

        if(dist>d[loc]){
            continue;
        }
        for(int i=0;i<vec[loc].size();i++){
            int vdist=vec[loc][i].first;
            int vloc=vec[loc][i].second;
            if(vloc==y) continue;
            
            if(vdist+dist<d[vloc] ){
                d[vloc]=vdist+dist;
                pque.push(make_pair(d[vloc],vloc));
            }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> x >> y >> z;

        vec[x].push_back(make_pair(z,y));

    }
    //x: 출발 y: 거점 z: 도착지
    cin >> x >>y >>z;
    fill(&d[0],&d[N+1], INF );
    digkstra(x);    
    int xtoy=d[y];
    fill(&d[0],&d[N+1], INF );
    digkstra(y);
    int ytoz=d[z];

    fill(&d[0],&d[N+1], INF );
    digkstra2(x);    
    int xtoz=d[z];
    
    if(xtoy>=INF || ytoz>=INF){
        cout << -1<< ' ';
    }else{
        cout << xtoy+ytoz<< ' ';
    }
    if(xtoz>=INF){
        cout << -1<< ' ';
    }else{
        cout << xtoz << ' ';
    }
    
}