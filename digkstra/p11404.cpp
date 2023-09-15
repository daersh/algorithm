#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

typedef pair<int,int> pii;

//우선순위 큐는 디폴트가 큰걸 위로 하기 때문에 
//아래처럼 하면 작은게 우선순위로 들어감
priority_queue<pii, vector<pii>, greater<pii> > pque;
vector<pii> vec[1010];
int N,M, X;
int d [1010];
//
int arr[1010];
int dist;
int loc;

void digkstra(int start){
    pque.push(make_pair(0,start));
    d[start]=0;
    while (!pque.empty())
    {
        dist= pque.top().first;
        loc= pque.top().second;
        pque.pop();
        if(d[loc]<dist){
            continue;
        }
        for(int i=0;i< vec[loc].size();i++){
            int next_val = vec[loc][i].first;
            int next_loc = vec[loc][i].second;

            if( next_val + dist < d[next_loc ]){
                d[next_loc]= next_val + dist;
                pque.push(make_pair( d[next_loc], next_loc));
            }
        }
    }
    
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> X;
    int x,y,z;

    for(int i=0;i<M;i++){
        cin >> x >> y >> z;
        vec[x].push_back(make_pair(z,y));
    }
    fill(&d[0],&d[1010],INF);
    digkstra(X);
    for(int i=1;i<=N;i++){
        arr[i]=d[i];
        // cout << arr[i] << ' ';
    }

    for(int i=1;i<=N;i++){

        fill(&d[0],&d[1010],INF);

        digkstra(i);
        arr[i]+=d[X];
    }    
    int result=-1;
    for(int i=1;i<=N;i++){
        if(result< arr[i]){
            result= arr[i];
        }
    }    
    cout << result;
    return 0;
}

