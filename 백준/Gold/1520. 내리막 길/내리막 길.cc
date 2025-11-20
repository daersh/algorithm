#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int,int>;
using piii = pair<int,pair<int,int> >;

pii next_loc[4] = {{0,1},{1,0},{-1,0},{0,-1}};

int main(){
    long long cnt=0;
    int n,m;
    cin >> n >> m;
    int arr[n][m];
    int visited[501][501]={0,};
    int visited2[501][501]={0,};

    for(int i=0; i< n; i++){
        for(int j=0;j<m;j++){
            cin >>arr[i][j];
        }
    }
    priority_queue<piii,vector<piii>, less<piii> > q;
    q.push({arr[0][0],{0,0}});
    visited[0][0]=1;
    while (!q.empty()){
        piii loc = q.top();
        q.pop();
        int x= loc.second.first;
        int y= loc.second.second;
        if(visited2[x][y]==1)
            continue;
        visited2[x][y]=1;
        // visited[x][y]++;
        // cout << "visit "<<x<<' '<<y<<'\n';
        for(pii next_v:next_loc){
            int next_x = x+next_v.first;
            int next_y = y+next_v.second;
            if(next_x<0 ||next_y<0 ||next_x>=n ||next_y>=m || 
                arr[next_x][next_y]>=arr[x][y] 
                || visited2[next_x][next_y]) 
                continue;
            if(visited[next_x][next_y]>0){
                // cout << next_x<<' '<<next_y <<" is already visited..\n";
                visited[next_x][next_y]+=visited[x][y];
                continue;
            }else{
                visited[next_x][next_y]=visited[x][y];
                // cout << "   next: "<<next_x <<' '<<next_y<<'\n';
                q.push({arr[next_x][next_y],{next_x,next_y}});
            }
        }
    }
    // for(int i=0; i< n; i++){
    //     for(int j=0;j<m;j++){
    //         cout << visited[i][j];
    //     }cout<<'\n';
    // }
    cout <<visited[n-1][m-1];
}