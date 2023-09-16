#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

// 가로 세로
int M, N;
// data 저장
int arr[1010][1010];
int visited[1010][1010];
int result;

queue<pii> q;
queue<pii> q2;

int arr2[1010][1010];

int arr3[1010][1010];
int visited2[1010][1010];
int cnt=1;

void bfs(){

  //시작지점 
  q.push(make_pair(0,0) );
  arr2[0][0]=1;
  

  while(!q.empty() || !q2.empty()){
    cnt+=1;
    int z= q.size();
    for(int k=0;k<z;k++){
      int x= q.front().first;
      int y = q.front().second;
      q.pop();
        if(visited[x][y]==true){
          continue;
        }
        visited[x][y]=true;
        visited2[x][y]=true;
        
        int x_new[4]= {0,0, -1,  1};
        int y_new[4]= {1,-1,0,0};

        for(int i=0;i<4;i++){
          int x_val= x+x_new[i];
          int y_val= y+y_new[i];
          if(x_val>=0 && x_val<N && y_val>=0 && y_val<M && visited[x_val][y_val]==false){
            if(arr[x_val][y_val]==0){
              visited2[x][y]=true;
              arr2[x_val][y_val]=cnt;
              q.push(make_pair(x_val,y_val));
            }
            else if(arr[x_val][y_val]==1){
              arr3[x_val][y_val]=cnt;
              q2.push(make_pair(x_val,y_val));
            }
          }
        }
    }


    int z2= q2.size();
    for(int k=0;k<z2;k++){
      int x= q2.front().first;
      int y = q2.front().second;
      q2.pop();
        //벽일 때 벽을 넘었다는 가정으로 그 주변으로 이동하는 예외상황 배열에 추가
      if(visited2[x][y]==true){
          continue;
      }

        visited2[x][y]=true;
        int x_new[4]= {0,0, -1,  1};
        int y_new[4]= {1,-1,0,0};

        for(int i=0;i<4;i++){
          int x_val= x+x_new[i];
          int y_val= y+y_new[i];

          if(x_val>=0 && x_val<N && y_val>=0 && y_val<M && visited2[x_val][y_val]==false){
            
            if(arr[x_val][y_val]==0){
              arr3[x_val][y_val]=cnt+1;
              q2.push(make_pair(x_val,y_val));
            }
          }
        }

    }
  
  }
}

int main() {
  int i, j;
  int x, y;
  scanf("%d", &N);  
  scanf("%d",&M);
  //벽 입력
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      scanf("%1d", &arr[i][j]);
    }
  }


  bfs();  
  

  if(arr2[N-1][M-1]!=0 && arr2[N-1][M-1] <= arr3[N-1][M-1]){
    cout << arr2[N-1][M-1]; 
  }else if(arr3[N-1][M-1]!=0 && arr3[N-1][M-1] < arr2[N-1][M-1]){
    cout << arr3[N-1][M-1];
  }else if(arr2[N-1][M-1]==0 && arr3[N-1][M-1]!=0){
    cout << arr3[N-1][M-1];
  }else if(arr3[N-1][M-1]==0 && arr2[N-1][M-1]!=0){
    cout << arr2[N-1][M-1];
  }
  else{ 
    cout << -1;
  }

}
