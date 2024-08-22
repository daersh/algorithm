#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
vector<pii> vec[100010];
int n , m;
int visited[100010];
int s,e;
int l= 1;
int r = 1e9;

int bfs(int mid){
    // mid : 무게
    
    queue<int> q;
    q.push(s);

    while (!q.empty()) 
    {
        int loc = q.front();
        q.pop();
        
        if(visited[loc])continue;
        visited[loc] = true;

        for(int i=0; i<vec[loc].size(); i++){
            int next_loc = vec[loc][i].first;
            int next_weight = vec[loc][i].second;
            
            if(visited[next_loc] ==0 && next_weight >= mid){
                q.push(next_loc);
            }
        }
    }

    return visited[e];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n >> m;
    cin >> s >> e;


    for(int i = 0; i < m; i++){
        int x , y, z;
        cin >> x >> y >> z;

        vec[x].push_back(make_pair(y,z));
        vec[y].push_back(make_pair(x,z));
    }




    while(l+1<r){
        int mid = (l+r)/2;
        fill(&visited[0],&visited[n+1],0);
        int result = bfs(mid);
        if(result == false) r = mid;
        else
            l=mid;

        // cout << "l = " << l << " r = " << r <<'\n';
    }
    
    fill(&visited[0],&visited[n+1],0);
    int result = bfs(r);
    if(result){
        cout << r;
    }else{
        cout << l;
    }
}