#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int > pii;


int n;
vector<pii> vec[510];
const int INF =1e9;
int d[510];

void digkstra(int start){
    priority_queue<pii, vector<pii>, greater<pii> > pque;
    pque.push(make_pair(0,start));
    d[start]=0;

    while(!pque.empty()){
        int dd= pque.top().first;
        int ll = pque.top().second;
        pque.pop();

        if(d[ll]<dd )continue;

        for(int i=0;i<vec[ll].size();i++){
            int ddd= vec[ll][i].first;
            int lll= vec[ll][i].second;

            if(ddd+dd < d[lll]){
                d[lll]= ddd+dd;
                pque.push(make_pair(d[lll], lll));
            }
        }
    }
}

int main(){
    cin >> n;
    int x,y;
    for(int i=0;i<n;i++){
        cin >> x >>y;
        vec[x].push_back(make_pair(1,y));
    }
    fill(&d[0],&d[510],INF);
    digkstra(1);
    for(int i=1;i<n+1;i++){
        cout << d[i]<< ' ';
    }



}