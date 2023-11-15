#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> pii;
const int INF = 1e9;
//값 저장
vector<pii> arr[101];
//거리
int d[101];
//도달한거리 합
int sumval[101];
vector<int> result;


void bfs(int a){

    priority_queue<pii,vector<pii>, greater<pii> > pque;
    pque.push(make_pair(0,a));

    while(!pque.empty()){
        int dd= pque.top().first;
        int ll= pque.top().second;
        pque.pop();
        if(dd>d[ll]){
            continue;
        }
        for(int i=0;i<arr[ll].size();i++){
            int ddd= arr[ll][i].first;
            int lll= arr[ll][i].second;
            if(ddd+dd<d[lll]){
                d[lll]=ddd+dd;
                pque.push(make_pair(d[lll],lll));
            }
        }
    }
}

void sumloc(int a,int n){
    vector<int>cmp;
    for(int i =0;i<n;i++){
        if(d[i]!=INF){
            cmp.push_back(i);
            sumval[a]+=d[i];
        }
    }

    while(!cmp.empty()){
        int cc= cmp.back();
        cmp.pop_back();
        if(sumval[cc]<)
    }
    
}


int main(){
    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >>y;
        arr[x].push_back(make_pair(1,y));
        arr[y].push_back(make_pair(1,x));
    }

    for(int i=1;i<=n;i++){
        fill(&d[0],&d[101],INF);
        bfs(i);
        sumloc(i,n);
        cout << i<<":  "<<sumval[i] <<'\n';
    }
    

}