#include <bits/stdc++.h>

using namespace std;

// 가로 세로
int M, N,O;
// data 저장
int arr[101][101][101];
// 방문한 노드인지 확인
int arr2[101][101][101];

//dfs 돌 큐들
queue<tuple<int, int, int> > q;
int count1=0;
void dfs(int x, int y, int z){

  arr2[x][y][z]=true;
  
  if(x!=0 && arr2[x-1][y][z]==false && arr[x-1][y][z]== 0){
    arr[x-1][y][z]=1;
    q.push(make_tuple(x-1,y,z));
  }
  if(x!=N-1 && arr2[x+1][y][z]==false && arr[x+1][y][z]== 0){
    arr[x+1][y][z]=1;
    q.push(make_tuple(x+1,y,z));
  }
  if(y!=0 && arr2[x][y-1][z]==false && arr[x][y-1][z]== 0){
    arr[x][y-1][z]=1;
    q.push(make_tuple(x,y-1,z));
  }
  if(y!=M-1 && arr2[x][y+1][z]==false && arr[x][y+1][z]== 0){
    arr[x][y+1][z]=1;
    q.push(make_tuple(x,y+1,z));
  }if(z!=0 && arr2[x][y][z-1]==false && arr[x][y][z-1]== 0){
    arr[x][y][z-1]=1;
    q.push(make_tuple(x,y,z-1));
  }if(z!= O-1 && arr2[x][y][z+1]==false && arr[x][y][z+1]== 0){
    arr[x][y][z+1]=1;
    q.push(make_tuple(x,y,z+1));
  }
  
}

int main(){
      ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

  int i, j;
  
  cin >> M >> N >> O;
  for(int k=0;k<O;k++){
    for(i=0; i<N; i++){
      for(j=0;j<M;j++){
        cin >> arr[i][j][k];
        if(arr[i][j][k]==1){
          q.push(make_tuple(i,j,k));
        }
      }
    }
  }
  
  while(q.empty()!=true){
    int z = q.size();
    for(i=0;i<z;i++){
      
      int num1 = get<0>(q.front());
      int num2 = get<1>(q.front());
      int num3 = get<2>(q.front());
      q.pop();
      dfs(num1, num2, num3);
    }

    count1++;
  }
  
  count1 -=1;

  for(int k=0;k<O;k++){
    for(i=0; i<N; i++){
      for(j=0;j<M;j++){
        if(arr[i][j][k]==0){
          count1=-1;
        }
      }
    }
  }


  cout << count1;
  
}