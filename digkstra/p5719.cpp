#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int INF  = 1e9;
typedef pair<int,int> pii;
int s,e,n,m;
int d[510];

void dig(vector<pii> *vec, int *back, vector<int> *saved,int start){
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push(make_pair(0,start));
    d[s]=0;
    vector<int> back2[n];

    while(!pq.empty())
    {
        int dd = pq.top().first;
        int ll = pq.top().second;
        pq.pop();
        if(dd>d[ll]) continue;
        for(int i=0; i< vec[ll].size(); i ++){
            int ddd = vec[ll][i].first;
            int lll = vec[ll][i].second;
            int tf=true;
            for(int j=0; j<saved[ll].size();j++){
                if(saved[ll][j]==lll){
                    tf=false;
                }
            }
            if(ddd+dd<d[lll] && tf ==true){
                //cout << ll<< " -> " <<lll<< '\n';
                back[lll]=ll;
                back2[lll].push_back(ll);
                d[lll]=ddd+dd;    
                pq.push(make_pair(d[lll],lll));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    while (1)
    {
        n= 1; m= 1;
        //insert
        cin >> n >> m;
        if ( n== 0 && m == 0) break;
        vector<pii> vec[n];
        vector<int> saved[n];
        vector<pii> backtracking[n];
        cin >> s >> e;

        for(int i=0; i< m; i++){
            int x, y, z;
            cin >> x >> y >> z;
            vec[x].push_back(make_pair(z,y));
            backtracking[y].push_back(make_pair(z,x));
        }
        fill(&d[0],&d[n],INF);
        int back[n];
        fill(&back[0],&back[n],-1);

        dig(vec,back,saved,s);
        int min_val = d[e];
        int cmp_val = min_val;
        //cout << min_val<<'\n';
        
        int check_point = e;
        queue<int> next_loc;
        next_loc.push(e);
        int visited[510]= {0};
        while(!next_loc.empty()){
            int cmp = next_loc.front();
            next_loc.pop();
            if(visited[cmp]==1) continue;
            visited[cmp]=1;
            for(int i=0;i<backtracking[cmp].size();i++){
                int dist = backtracking[cmp][i].first ;
                int loc  = backtracking[cmp][i].second;
                
                if(d[loc]+dist==d[cmp]){
                    saved[loc].push_back(cmp);
                    next_loc.push(loc);
                }
            }
        }
        fill(&d[0],&d[n],INF);
        dig(vec,back,saved,s);
        if(d[e]>=INF) cout << "-1\n";
        else cout << d[e]<<'\n';
    }
    
}
