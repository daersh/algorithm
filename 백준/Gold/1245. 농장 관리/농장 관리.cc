#include <iostream>
#include <queue>
#include <cmath>
#include <vector> 
using namespace std;
using pii= pair<int,int> ;
using asdf= pair<int, pair<int,int>>;

int n, m;
pii next_arr[8]= {{1,1},{1,0},{0,1},{-1,-1},{-1,0},{0,-1},{1,-1},{-1,1} };

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    cin >> n >> m;
    int arr[n][m];
    int visited[n][m];
    priority_queue<asdf, vector<asdf>, less<asdf> > pq;
    for(int i=0; i< n; i++){
        for(int j=0; j< m; j++){
            int x; 
            cin >> x;
            arr[i][j]=x;
            visited[i][j]=0;    
            pq.push({x,{i,j}});
        }
    }

    int cnt=0;
    while (!pq.empty())
    {
        asdf data = pq.top();
        pq.pop();
        int i= data.second.first;
        int j = data.second.second;
        // cout << i<<' '<<j<<':'<<data.first <<'\n';
        if(visited[i][j] || arr[i][j]==0) continue;
        queue<pii> q;
        q.push({i,j});
        visited[i][j]=1;
        cnt++;
        q.push({i,j});
        
        while (!q.empty()){
            pii loc = q.front();
            q.pop();
            for(pii next_v: next_arr){
                int x=loc.first+next_v.first;
                int y=loc.second+next_v.second;
                if( x>=n || y>=m || x<0 || y<0 || visited[x][y]) 
                    continue;
                if(arr[x][y]>arr[loc.first][loc.second]){
                    continue;
                }

                visited[x][y]=1;
                q.push({x,y});
            }
        }
    }
    cout << cnt;
}
