#include<iostream>
#include<vector>
#include<queue>

using namespace std;
const int INF = 1e9;
typedef pair<int,int> pii;

//X: 파티 열리는 곳
int N,M,X;


vector<pii> vec[1010];
int d[1010];


void digkstra(){
    priority_queue <pii, vector<pii>, greater<pii> >pque;

    pque.push(make_pair(0,X));
    d[X]=0;

    while(!pque.empty()){

        int dd=pque.top().first;
        int ll= pque.top().second;
        pque.pop();

        if(dd>d[ll]) {continue;}

        for(int i=0;i<vec[ll].size();i++){
            int ddd= vec[ll][i].first;
            int lll= vec[ll][i].second;

            if(dd+ddd<d[lll]){
                d[lll]=dd+ddd;
                pque.push(make_pair(d[lll],lll));
            }
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M>> X;
    
    //a - b   distance=z;
    int a,b,c;
    fill(&d[0],&d[1010],INF);

    for(int i=0;i<M;i++){
        cin >> a >> b>> c;
        vec[a].push_back(make_pair(c,b));
        vec[b].push_back(make_pair(c,a));
    }
    digkstra();
    int max=0;

    for(int i=1;i<=N;i++){
        if(d[i]>max){
            max=d[i];
        }
    }
    cout << max*2;

}