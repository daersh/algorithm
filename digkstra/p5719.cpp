#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 1e9;
typedef pair<int,int> pii;

int n, m;
int s, e;
vector<pii> vec[510];
int back[510]; //역추적s
int d[510]; //거리
int enabled[510]; //1일때 통과 불가
int endPoint[510];
int min_len= INF;
int cnt=0;

void digkstra(){
    priority_queue<pii, vector<pii>,greater<pii> > pque;
    d[s]= 0;
    pque.push(make_pair(0,s));

    while (!pque.empty())
    {
        int dd= pque.top().first;
        int ll= pque.top().second;
        pque.pop();

        if(dd>d[ll])continue;

        for(int i=0;i<vec[ll].size();i++){
            int ddd= vec[ll][i].first;
            int lll= vec[ll][i].second;
            if(enabled[lll]==true) continue;
            if(ddd+dd<d[lll]){
                back[lll]=ll;
                d[lll]=ddd+dd;

                if(lll==e){
                    if(min_len>d[lll]){
                        cnt=0;
                        min_len=d[lll];
                    }
                    cout << ll<<'\n';
                    endPoint[cnt]=ll;
                    cnt++;
                }
                pque.push(make_pair(d[lll],lll));
           }else if(d[lll]==ddd+dd){
                endPoint[cnt]==ll;
                cnt++;
           }

        }
    }   
}

void backtracking(){
    
}

int main(){

    while(1){
        cin >> n >> m;
        cin >> s >> e;

        for(int i=0 ;i<m;i++){
            int x,y,z;
            cin >> x>>y>>z;
            vec[x].push_back(make_pair(z,y));
            vec[y].push_back(make_pair(z,x));
        }
        fill(&d[0],&d[n],INF);
        digkstra();

        for(int i=0;i<n;i++){
            cout << back[i] << ' ';
        }cout<<'\n';
        for(int i=0;i<n;i++){
            cout << d[i] << ' ';
        }cout<<'\n';
        for(int i=0;i<cnt;i++){
            cout << endPoint[i]<<' ';
        }

    }
    
}