#include <bits/stdc++.h>>

using namespace std;

// 가로 세로
int M, N;
// data 저장
int arr[1010][1010];
// 방문한 노드인지 확인
int arr2[1010][1010];

//dfs 돌 큐들
queue<pair<int, int>> q;
int count1=0;
void dfs(int x, int y){

  arr2[x][y]=true;
  
  if(x!=0 && arr2[x-1][y]==false && arr[x-1][y]== 0){
    arr[x-1][y]=1;
    q.push(make_pair(x-1,y));
  }
  if(x!=N-1 && arr2[x+1][y]==false && arr[x+1][y]== 0){
    arr[x+1][y]=1;
    q.push(make_pair(x+1,y));
  }
  if(y!=0 && arr2[x][y-1]==false && arr[x][y-1]== 0){
    arr[x][y-1]=1;
    q.push(make_pair(x,y-1));
  }
  if(y!=M-1 && arr2[x][y+1]==false && arr[x][y+1]== 0){
    arr[x][y+1]=1;
    q.push(make_pair(x,y+1));
  }
  
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
  int i, j;
  int x, y;
  cin >> M >> N;
  for(i=0; i<N; i++){
    for(j=0;j<M;j++){
      cin >> arr[i][j];
      if(arr[i][j]==1){
        q.push(make_pair(i,j));
      }
    }
  }
  
  while(q.empty()!=true){
    int z = q.size();
    for(i=0;i<z;i++){
      
      int num1 = q.front().first;
      int num2 = q.front().second;
      //printf("%d일차 담긴 값들: %d, %d \n", count1, num1, num2);
      q.pop();
      dfs(num1, num2);
    }
    /*
    for(i=0; i<N; i++){
    for(j=0;j<M;j++){
      if(arr[i][j]==0){
        cout << arr[i][j]<< ' ';
        }
      }
      cout << '\n';
    }*/
    count1++;
  }
  count1 -=1;
  int tf =0;
  for(i=0; i<N; i++){
    for(j=0;j<M;j++){
      if(arr[i][j]==0){
        count1=-1;
      }
    }
  }
  
  cout << count1;
  
}