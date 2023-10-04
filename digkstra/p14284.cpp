#include<iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> pii;
const int INF =1e9;

int d[5010];
vector<pii> vec[5010];
int N,M;

void digkstra(int start){
    priority_queue<pii,vector<pii>,greater<pii> > pque;

    pque.push(make_pair(0,start));
    d[start]=0;

    while (!pque.empty())
    {
        int dd = pque.top().first;
        int ll= pque.top().second;
        pque.pop();

        if(dd>d[ll]) continue;

        for(int i=0;i<vec[ll].size();i++){
            int ddd= vec[ll][i].first;
            int lll= vec[ll][i].second;
            if(ddd+dd < d[lll]){
                d[lll]=ddd+dd;
                pque.push(make_pair(d[lll],lll));
            }
        }
    }
}


int main(){
    cin >> N >> M;
    int x,y,z;
    for(int i=0;i<M;i++){
        cin >> x >>y>>z;
        vec[x].push_back(make_pair(z,y));
        vec[y].push_back(make_pair(z,x));
    }
    int start,end;
    cin >>start >> end;

    fill(&d[0],&d[N+1],INF);
    digkstra(start);
    
    cout << d[end] ;

    return 0;
}