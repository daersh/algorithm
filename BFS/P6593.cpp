#include <bits/stdc++.h>>

using namespace std;

// 가로 세로
int M, N;
// data 저장
char arr[1010][1010];
// 방문한 노드인지 확인
int visited[1010][1010];

int start_point[2];
int end_point[2];

//dfs 돌 큐들
queue<pair<int, int>> q;
int count1=0;

void bfs(){
  while (/* condition */)
  {
    /* code */
  }
  
  visited[][]=true;
  
  if(x!=0 && visited[x-1][y]==false && arr[x-1][y]== 0){
    arr[x-1][y]=1;
    q.push(make_pair(x-1,y));
  }
  if(x!=N-1 && visited[x+1][y]==false && arr[x+1][y]== 0){
    arr[x+1][y]=1;
    q.push(make_pair(x+1,y));
  }
  if(y!=0 && visited[x][y-1]==false && arr[x][y-1]== 0){
    arr[x][y-1]=1;
    q.push(make_pair(x,y-1));
  }
  if(y!=M-1 && visited[x][y+1]==false && arr[x][y+1]== 0){
    arr[x][y+1]=1;
    q.push(make_pair(x,y+1));
  }
  
}

int main(){
  int i, j;
  int x, y;
  cin >> M >> N;

  for(i=0; i<N; i++){
    for(j=0;j<M;j++){
      cin >> arr[i][j];
      if(arr[i][j]=='S'){
        start_point[0]=i;
        start_point[1]=j;
        q.push(make_pair(i,j));
      }else if(arr[i][j]=='E'){
        end_point[0]=i;
        end_point[1]=j;
      }
    }
  }

  
}