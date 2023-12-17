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
            
        }
    }
    
}

int main(){

    for(int i=0 ;i<9;i++){
        int x,y,z;
        cin >> x>>y>>z;
        vec[x].push_back(make_pair(z,y));
        vec[y].push_back(make_pair(z,x));
    }
    fill(&d[0],&d[n],INF);

}