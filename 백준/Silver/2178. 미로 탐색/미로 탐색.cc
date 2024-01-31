#include <bits/stdc++.h>>

using namespace std;
#define used 1
#define notused 0

// 가로 세로
int M, N;
// data 저장
int arr[1100][1100];
int arr2[1100][1100];

int number = 1;
int visited[1100][1100];
queue<pair<int,int> > q;

void bfs(int x, int y){
    q.push(make_pair(x,y));
    visited[x][y] = true;
    
    while(!q.empty()){

      int x = q.front().first;
      int y = q.front().second;
      q.pop();
          
        
        if(x!=N-1 && arr[x+1][y]==1){    
          if(!visited[x+1][y]){  
            arr2[x+1][y]= arr2[x][y]+1;
            q.push(make_pair(x+1,y)); 
            visited[x+1][y] = true; 
          }
        }
         if(y!=M-1 && arr[x][y+1]==1) {    
          if(!visited[x][y+1]){  
            arr2[x][y+1]= arr2[x][y]+1;
            q.push(make_pair(x,y+1)); 
            visited[x][y+1] = true; 
          }
        }
      if(x!=0 && arr[x-1][y]==1){
          if(!visited[x-1][y]){ 
            arr2[x-1][y]= arr2[x][y]+1;
            q.push(make_pair(x-1,y)); 
            visited[x-1][y] = true; 
          }
      }
        if(y!=0 && arr[x][y-1]==1) {    
          if(!visited[x][y-1]){  
            arr2[x][y-1]= arr2[x][y]+1;
            q.push(make_pair(x,y-1)); 
            visited[x][y-1] = true; 
          }
        }
     
      }
}


int main(){    
  //ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
  int i, j;
  int x, y;
  cin >> N >> M;
  for(i=0; i<N; i++){
    for(j=0;j<M;j++){
      scanf("%1d",&arr[i][j]);
    }
  }


  arr2[0][0]= 1;
  bfs(0,0);  
  /*
  for(int i=0; i< N; i++){
    for(int j=0; j<M; j++){
      cout << arr2[i][j] << ' ';
    }
    cout << '\n';
  }*/
  printf("%d", arr2[N-1][M-1]);
}
