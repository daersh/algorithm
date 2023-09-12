#include <bits/stdc++.h>


using namespace std;


int N,M,K;
int visited[2010][2010];
int arr[1010][1010];
int arr2[1010][1010];


pair<int,int> start_point;

queue<pair<int,int> > q;
int x_dir[4] = {-1, 1, 0, 0};   // 상화좌우 x축 방향
int y_dir[4] = {0, 0, -1, 1};   // 상화좌우 y축 방향
int count1=0;
int sword;
pair<int,int> sword_loc;

void bfs();

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int i,j;
    cin >> N >> M >> K;
    int x;
    int y;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            cin >> arr[i][j];
            if(arr[i][j]==2){
                sword_loc= make_pair(i,j);
                arr[i][j]=0;
            }
            
        }
    }
    
    q.push(make_pair(0,0));
    bfs();

    int sword_x= sword_loc.first;
    int sword_y= sword_loc.second;
    
    if(visited[sword_x][sword_y]==true){
        
        int sword_len= arr[sword_x][sword_y] + N + M -2 - sword_x - sword_y;
        //cout << "sword 위치: [" <<sword_x << ", "<< sword_y  << "], 공주위치와의 거리: "<< sword_len <<'\n';
        if(sword_len< arr[N-1][M-1]){
            arr[N-1][M-1]= sword_len;
        }
        if(visited[N-1][M-1]==false){
            arr[N-1][M-1]= sword_len;
            visited[N-1][M-1]=true;
        }
    }

    
    if(visited[N-1][M-1]==true && arr[N-1][M-1]<= K ){
        cout << arr[N-1][M-1];
    }else{
        cout << "Fail";
    }
    
}



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
            && !visited[x_new][y_new] && arr[x_new][y_new] == 0 ){
                arr[x_new][y_new] = count1+1;
                q.push(make_pair(x_new,y_new)); 
            }
        }
        z--;
    }
        count1++;
    }

}