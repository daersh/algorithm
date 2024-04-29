#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int n,m;
int xn[4] = {1,-1,0,0};
int yn1[4] = {0,0,1,-1};
int visited[550][550];
int arr[550][550];
int vals[550][550];
int result;

int dfs(int x, int y){
    if(x==n-1 && y==m-1){
        vals[x][y]++;
        return 1;
    }
    
    visited[x][y] = true;
    int v;
    for(int i = 0; i < 4; i++){
        int nx = x + xn[i];
        int ny = y + yn1[i];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= m|| visited[nx][ny] == true || vals[nx][ny] == -1){
            continue;
        }
        if(vals[nx][ny]!=0){
            result += vals[nx][ny];
            continue;
        }
        v= dfs(nx,ny);
        if(v==-1){
            vals[nx][ny] = -1;
        }
    }
    return v;
}


int main(){
    cin >> n >> m;
    
    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }
    dfs(0,0);
    cout << result << '\n';
    printf("sksdfsdf");
    return 0;
}
