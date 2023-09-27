#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
typedef pair<int,int> pii;


int N,M;
int f[3];
vector<pii> vec[100010];
long long d[100010];
long long d2[100010];
long long d3[100010];



void digkstra(int start){
    priority_queue<pii, vector<pii>, greater<pii> > pque;
    pque.push(make_pair(0,start));
    
    while(!pque.empty()){
        int dd=pque.top().first;
        int ll=pque.top().second;
        pque.pop();
        if(dd>d[ll]){
            continue;
        }
        for(int i=0;i<vec[ll].size();i++){
            int ddd= vec[ll][i].first;
            int lll = vec[ll][i].second;
            if(ddd+dd < d[lll]){
                d[lll]=ddd+dd;
                pque.push(make_pair(d[lll],lll));
            }
        }
    }
    
}

void digkstra2(int start){
    priority_queue<pii, vector<pii>, greater<pii> > pque;
    pque.push(make_pair(0,start));
    
    while(!pque.empty()){
        int dd=pque.top().first;
        int ll=pque.top().second;
        pque.pop();
        if(dd>d2[ll]){
            continue;
        }
        for(int i=0;i<vec[ll].size();i++){
            int ddd= vec[ll][i].first;
            int lll = vec[ll][i].second;
            if(ddd+dd < d2[lll]){
                d2[lll]=ddd+dd;
                pque.push(make_pair(d2[lll],lll));
            }
        }
    }
    
}

void digkstra3(int start){
    priority_queue<pii, vector<pii>, greater<pii> > pque;
    pque.push(make_pair(0,start));
    
    while(!pque.empty()){
        int dd=pque.top().first;
        int ll=pque.top().second;
        pque.pop();
        if(dd>d3[ll]){
            continue;
        }
        for(int i=0;i<vec[ll].size();i++){
            int ddd= vec[ll][i].first;
            int lll = vec[ll][i].second;
            if(ddd+dd < d3[lll]){
                d3[lll]=ddd+dd;
                pque.push(make_pair(d3[lll],lll));
            }
        }
    }
    
}
//50,000,000,000

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0;i<3;i++){
        cin >> f[i];
    }

    cin >> M;
    int x,y,z;
    fill(&d[0],&d[N+1],INF);
    fill(&d2[0],&d2[N+1],INF);
    fill(&d3[0],&d3[N+1],INF);

    for(int i=0;i<M;i++){
        cin >>x >> y >> z;
        vec[x].push_back(make_pair( z,y));
        vec[y].push_back(make_pair(z,x));
    }

    digkstra(f[0]);
    digkstra2(f[1]);
    digkstra3(f[2]);

    long long result = -1;
    long long loc=-1;

    for(int i=1;i<=N;i++){
        
        long long cmp = min( min(d[i],d2[i]),d3[i] );
        
        if(cmp>result){
            result=cmp;
            loc=i;
        }

    }

    cout << loc;
}