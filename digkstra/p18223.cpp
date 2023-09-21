#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;

const int INF = 1e9;

int arr[5010];
//정점, 간선, 친구위치
int V , E, P;
vector<pii> vec[5010];
int d[5010];


void digkstra(int x){
    fill(&d[0],&d[5010],INF);
    priority_queue<pii,vector<pii>,greater<pii> > pque;
    pque.push(make_pair(0,x));
    d[x]=0;

    while (!pque.empty())
    {
        int pque_dist= pque.top().first;
        int pque_loc = pque.top().second;
        pque.pop();
        if(pque_dist > d[pque_loc]){
            continue;
        }

        for(int i=0;i<vec[pque_loc].size();i++){
            int vec_dist= vec[pque_loc][i].first;
            int vec_loc = vec[pque_loc][i].second;

            if(pque_dist+vec_dist<d[vec_loc] ){
                d[vec_loc]= pque_dist+vec_dist;
                pque.push(make_pair(d[vec_loc],vec_loc ));
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> V >> E >> P;
    int x, y, z;

    for(int i=1;i<=E ; i++){
        cin >> x >> y >> z;
        vec[x].push_back(make_pair(z,y));
        vec[y].push_back(make_pair(z,x));
    }
    //시작지점-> 끝지점의 d와 시작지점-> 건우까지의 d + 건우->끝지점까지의 d 구하면 됨
    //끝지점 = V
    digkstra(1);
    int StoD= d[V];
    int StoG= d[P];
    digkstra(P);
    int GtoD= d[V];
    if(StoD == StoG+GtoD){
        cout << "SAVE HIM";
    }else{
        cout << "GOOD BYE";
    }
}