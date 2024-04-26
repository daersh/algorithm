#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 1e9;
typedef pair<int,int> pii;

int main(){
    int n, m;
    cin >> n >> m;
    int result[n+1];
    vector<pii> vec[n+1];
    for(int i=0; i< m ;i++){
        int x,y,z;
        cin >> x >> y >> z;
        vec[x].push_back(make_pair(z,y));
        vec[y].push_back(make_pair(z,x));
    }
    int d[n+1];
    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.push(make_pair(0,2));
    int cnt[n+1];
    fill(&d[0],&d[n+1],INF);
    fill(&cnt[0],&cnt[n+1],0);
    cnt[2]=1;
    d[2]=0;
    while(!q.empty()){
        int dd = q.top().first;
        int ll = q.top().second;
        q.pop();
        if(dd>d[ll]) continue;
        for(int i=0; i< vec[ll].size();i++){
            int ddd = vec[ll][i].first;
            int lll = vec[ll][i].second;
            if(ddd+dd < d[lll]){
                d[lll]= ddd+dd;
                q.push(make_pair(d[lll],lll));
            }
            if(d[ll]<d[lll]){
                cnt[lll]+=cnt[ll];
            }
        }
    }
    cout << cnt[1]<<'\n';
}