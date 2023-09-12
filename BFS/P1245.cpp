#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[110][110];
int visited[110][110];
int total;
queue<pair<int,int> > q;


int x_dir[8] = {-1, 1, 0, 0 , 1 , 1, -1, -1};   // 상화좌우 x축 방향
int y_dir[8] = {0, 0, -1, 1 , 1 , -1 , 1, -1};   // 상화좌우 y축 방향

int top;
int height[500];

int x;

int bfs(int x,int y ){
    x=arr[x][y];
    while (q.empty())
    {
        
        visited[x][y]==true;

        for (int i=0; i<4; ++i){
            
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

            if ( (0 <= x_new && x_new < N) && (0 <= y_new && y_new < M) 
            && !visited[x_new][y_new] && arr[x_new][y_new] == x ){
                q.push(make_pair(x_new,y_new)); 

            }   
             if ( (0 <= x_new && x_new < N) && (0 <= y_new && y_new < M) 
            && !visited[x_new][y_new] && arr[x_new][y_new]  ){
                

            }
        }

    }
    

}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            cin >> arr[i][j];
            height[arr[i][j]]=true;
            if(arr[i][j] > top){
                top=arr[i][j];
            }
        }
    }

    for(int k=1;k<top+1;k++){
        if(height[k]!=true) return;
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                if(arr[i][j]==k && visited[i][j] !=true ){
                    q.push(make_pair(i,j));
                    bfs(i,j);
                }
        }
        }
    }
    
    
    cout << total;
}