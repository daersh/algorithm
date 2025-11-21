#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
using pii= pair<int,int>;

pii n_l[4]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m;
int cnt=0;
queue<pii> q;
queue<pii> in;
int visited[101][101]={false};
int out[101][101]={false};
set<pii> asdf;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int arr[n][m];
    int total=n*m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    q.push({0,0});
    out[0][0]=true;
    while(!q.empty()){
        int x= q.front().first;
        int y= q.front().second;
        // cout <<"x: "<< x <<" y: "<< y <<"\n";
        q.pop();
        for(pii n_c:n_l){
            int nx= x+n_c.first;
            int ny= y+n_c.second;
            if(nx<0||ny<0||nx>=n||ny>=m||out[nx][ny]){
                continue;
            }
            if(arr[nx][ny]==1 ){
                visited[nx][ny]++;
                if(visited[nx][ny]>=1 && asdf.find({nx,ny})==asdf.end() ){
                    // cout << "   nx: "<< nx << " ny: "<<ny <<'\n';
                    asdf.insert({nx,ny});
                    in.push({nx,ny});
                }
            }else{
                out[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
    int ttt=in.size();
    while(!in.empty()){
        ttt=in.size();
        // cout << "in.size: "<< in.size() <<'\n';
        cnt++;
        while(!in.empty()){
            int x= in.front().first;
            int y= in.front().second;
            in.pop();
            q.push({x,y});
            arr[x][y]=0;
            out[x][y]=1;
        }
        // cout << "   in.size: "<< in.size() <<'\n';
        // cout << "   q.size: "<< q.size() <<'\n';
        while(!q.empty()){
            int x= q.front().first;
            int y= q.front().second;
            // cout << x<<' '<<y<<'\n';
            q.pop();
            for(pii n_c:n_l){
                int nx= x+n_c.first;
                int ny= y+n_c.second;
                if(nx<0||ny<0||nx>=n||ny>=m||out[nx][ny]){
                    continue;
                }
                if(arr[nx][ny]==1 ){
                    visited[nx][ny]++;
                    if(visited[nx][ny]>=1 && asdf.find({nx,ny})==asdf.end()){
                        // cout <<"    nx: "<<nx<< "ny:"<<ny <<'\n';
                        in.push({nx,ny});
                        asdf.insert({nx,ny});
                    }
                }else{
                    out[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
        // cout << "       in.size: "<< in.size() <<'\n';
        
    }
 
    cout << cnt<<'\n'<<ttt;
}