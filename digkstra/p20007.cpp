#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e9;

//N: 집 M: 도로 수   X: 하루 가능 거리  Y: 시작점
int N, M, X,Y;

vector<pii> vec[1010];
int d[1010];
priority_queue<int, vector<int>, greater<int> > visited;

void digkstra(int start){
    priority_queue<pii, vector<pii>, greater<pii> > pque;

    pque.push(make_pair(0,start));
    d[start]=0;

    while(!pque.empty()){
        int dist = pque.top().first;
        int loc = pque.top().second;
        pque.pop();
        if(dist> d[loc]){
            continue;
        }
        for(int i=0;i<vec[loc].size();i++){
            int vec_dist= vec[loc][i].first;
            int vec_loc = vec[loc][i].second;
            if(vec_dist+dist < d[vec_loc]){
                d[vec_loc]= vec_dist+dist;
                pque.push(make_pair(d[vec_loc],vec_loc));
            }
        }
    }
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);


    cin >> N >> M >> X >>Y;
    int x,y,z;
    for(int i=0;i<M;i++){
        cin >> x >> y >> z;
        vec[x].push_back(make_pair(z,y));
        vec[y].push_back(make_pair(z,x));
    }  
    fill(&d[0],&d[1010],INF);
    digkstra(Y);
    int tf=false;
    
    for(int i=0;i<N;i++){

        //cout << d[i] << ' ';
         if(d[i]*2 > X){
            tf=true;
         }
        visited.push(d[i]*2);
    }
    
    if(tf==true){
        cout << -1;
        return 0;
    }
    int cnt=1;
    int past_val=X;
    while (!visited.empty())
    {
        
        int aa = visited.top();
        visited.pop();
        if(aa<=past_val){
            past_val -=aa;
        }else if(aa>past_val){
            cnt++;
            past_val=X;
            past_val-=aa;
        }
    }
    cout << cnt;
    

    return 0;
}

