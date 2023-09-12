#include <bits/stdc++.h>


using namespace std;
struct Data{
    char data;
    pair<int,int> loc;
    pair<int,int> past_loc;
    
}insert;

int N,M;
int visited[2010][2010];
struct Data arr[2010][2010];
struct Data start_point[2];

queue<struct Data> q;

void bfs();

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int i,j;
    cin >> N >> M;
    int x=0;
    int y;
    for(i=0;i<N;i++){
        string a;
        cin >> a;
        for(j=0;j<M;j++){
            if(a[j]=='.'){
                arr[i][j].data='@';
            }else arr[i][j].data= a[j];

            if(i==0 || j==0 || i== N-1 || j==M-1){
                if(arr[i][j].data=='@' && x<2){
                    start_point[x].loc= make_pair(i,j);
                    x++;
                }
            }

        }
    }

    q.push(start_point[0]);
    bfs();
    x= start_point[1].loc.first;
    y= start_point[1].loc.second;
    while(1){
        int z;
        arr[x][y].data= '.';
        z=x;
        x=arr[x][y].past_loc.first;
        y=arr[z][y].past_loc.second;
        if(x==start_point[0].loc.first && y==start_point[0].loc.second){
            arr[x][y].data= '.';
            break;
        }
        if(x==0 && y==0)break;
    }

    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            cout << arr[i][j].data;
        }
        cout <<"\n" ;
    }

}


int x_dir[4] = {-1, 1, 0, 0};   // 상화좌우 x축 방향
int y_dir[4] = {0, 0, -1, 1};   // 상화좌우 y축 방향

void bfs(){

    while(!q.empty()){
        int x = q.front().loc.first;
        int y = q.front().loc.second;
        pair<int,int> past_loc = q.front().loc;
        if(visited[x][y]==true) continue;
        visited[x][y]=true;
        q.pop();
        for (int i=0; i<4; ++i){
            
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

            if ( (0 <= x_new && x_new < N) && (0 <= y_new && y_new < M) 
            && !visited[x_new][y_new] && arr[x_new][y_new].data == '@' ){
                arr[x_new][y_new].loc = make_pair(x_new,y_new);
                arr[x_new][y_new].past_loc = past_loc;
                q.push(arr[x_new][y_new]); 
            }
        }
    }

}