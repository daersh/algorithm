#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;
int N,M;
vector<pii> vec[50010];
int d[50010];
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> N >> M;
    int x, y, z;
    for(int i=0;i<M;i++){
        cin >> x>>y>>z;
        vec[x].push_back(make_pair(z,y));
        vec[y].push_back(make_pair(z,x));
    }

    fill(&d[0],&d[N+1],INF);
    
    priority_queue <pii, vector<pii>, greater<pii> > pque;

    pque.push(make_pair(0,1));
    d[1]=0;

    while (!pque.empty())
    {
        int dist = pque.top().first;
        int loc = pque.top().second;
        pque.pop();

        if(dist>d[loc]){
            continue;
        }

        for(int i=0;i<vec[loc].size();i++){
            int vec_dist= vec[loc][i].first;
            int vec_loc = vec[loc][i].second;
            if(vec_dist+dist < d[vec_loc]){
                d[vec_loc]= vec_dist+dist;
                pque.push(make_pair( d[vec_loc], vec_loc));
            }
        }

    }
    cout << d[N];

}