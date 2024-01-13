#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

char arr[20][20];
bool visited[20][20];
int next_x[4]={0,0,1,-1};
int next_y[4]={1,-1,0,0};

void dfs(int x,int y){
    
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i< n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<n;i++){
        fill(&visited[i][0],&visited[i][m],false);
    }
    for(int i=0; i< n;i++){
        for(int j=0;j<m;j++){
            char start = arr[i][j];
            visited[i][j]==true;
            dfs(i,j);
            visited[i][j]==true;
        }
    }
}