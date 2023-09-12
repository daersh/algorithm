#include <bits/stdc++.h>


using namespace std;


int N,M;
int visited[2010][2010];
int arr[1010][1010];
int arr2[1010][1010];


pair<int,int> start_point;

queue<pair<int,int> > q;

void bfs();

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int i,j;
    cin >> N >> M;
    int x;
    int y;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            cin >> arr[i][j];
            if(arr[i][j]==2){
                x=i;
                y=j;
            }
        }
    }

    q.push(make_pair(x,y));
    bfs();
    arr[x][y]=0;
    
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(visited[i][j]==false){
                if(arr[i][j]==1){
                    cout << -1 << ' ';
                    continue;
                }
            }
            cout << arr[i][j]<< ' ';
            
        }
        cout << '\n';
    }
}


int x_dir[4] = {-1, 1, 0, 0};   // 상화좌우 x축 방향
int y_dir[4] = {0, 0, -1, 1};   // 상화좌우 y축 방향
int count1=0;

void bfs(){

    while(!q.empty()){
        
        int z= q.size();
        while(z!=0){
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y]=true;
        q.pop();

        for (int i=0; i<4; ++i){
            
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

            if ( (0 <= x_new && x_new < N) && (0 <= y_new && y_new < M) 
            && !visited[x_new][y_new] && arr[x_new][y_new] == 1 ){
                arr[x_new][y_new] = count1+1;
                q.push(make_pair(x_new,y_new)); 
            }
        }
        z--;
    }
        count1++;
    }

}