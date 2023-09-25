#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int > pii;

const int INF = 1e9;

int T;


void digkstra(int start, vector<pii> vec[], int *d){

    priority_queue<pii,vector<pii>,greater<pii> > pque;

    pque.push(make_pair(0,start));
    while (!pque.empty())
    {
        int dd = pque.top().first;
        int lloc = pque.top().second;
        pque.pop();

        if(dd>d[lloc]){
            continue;
        }
        for(int i=0;i<vec[lloc].size();i++){
            int ddd = vec[lloc][i].first;
            int llloc= vec[lloc][i].second;

            if(ddd+dd < d[llloc]){
                d[llloc]=ddd+dd;
                pque.push(make_pair( d[llloc],llloc));
            }
        }
    }
    

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for(int t=0;t<T;t++){
        int N, D, C;
        cin >> N >> D >>C;
        vector<pii> vec[N+1];
        int d[N+1];
        
        fill(&d[0],&d[N+1],INF);

        int x,y,z;
        for(int i=0;i<D;i++){
            cin >>x>>y>>z;
            vec[y].push_back(make_pair(z,x));
        }
        d[C]=0;
        digkstra(C, vec,d);
        int max=0;
        int cnt=0;
        for(int i= 1;i<=N;i++){
            if(d[i]<INF){
                cnt++;
                if(d[i]>max){
                    max=d[i];
                }
            }
        }
        cout << cnt << ' ' << max<< '\n';
    }

    
}