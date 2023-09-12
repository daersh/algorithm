#include <bits/stdc++.h>

using namespace std;

// 가로 세로
int M, N;
// data 저장
int arr[101][101];
// 방문한 노드인지 확인
int arr2[101][101];

//dfs 돌 큐들
queue<pair<int, int> > q;
int count1;

void dfs(int x, int y){

  arr2[x][y]=true;

  if(x!=0 && arr2[x-1][y]==false && arr[x-1][y]== 1){
  //  cout << "-> "<< x-1 << "," << y <<' ' ;
    dfs(x-1,y);
  }
  if(x!=N-1 && arr2[x+1][y]==false && arr[x+1][y]== 1){
  //  cout << "-> "<< x+1 << "," << y <<' ' ;
    dfs(x+1,y);
  }
  if(y!=0 && arr2[x][y-1]==false && arr[x][y-1]== 1){
 //   cout << "-> "<< x << "," << y-1 <<' ' ;
    dfs(x,y-1);
  }
  if(y!=M-1 && arr2[x][y+1]==false && arr[x][y+1]== 1){
//    cout << "-> "<< x<< "," << y+1 <<' ' ;
    dfs(x,y+1);
  }

  if(x!=0 && y!=0 && arr2[x-1][y-1]==false && arr[x-1][y-1]== 1){
  //  cout << "-> "<< x-1 << "," << y-1 <<' ' ;
    dfs(x-1,y-1);
  }
  if(x!=N-1 && y!=M-1 && arr2[x+1][y+1]==false && arr[x+1][y+1]== 1){
 //    cout << "-> "<< x+1 << "," << y+1 <<' ' ;
     dfs(x+1,y+1);
  }
  if(x!=N-1 && y!=0 && arr2[x+1][y-1]==false && arr[x+1][y-1]== 1){
 //    cout << "-> "<< x+1 << "," << y-1 <<' ' ;
     dfs(x+1,y-1);
  }
  if(x!=0 && y!=M-1 && arr2[x-1][y+1]==false && arr[x-1][y+1]== 1){
  //   cout << "-> "<< x-1 << "," << y+1 <<' ' ;
     dfs(x-1,y+1);
  }
}

int main(){
  int i, j;
  int x, y;

  while(1){
    memset(arr2,0,sizeof(arr2));

    count1=0;
    cin >> M >> N;
    //0 0 이면 종료
    if(M==0 && N==0) break;
    //배열 입력
    for(i=0; i<N; i++){
        for(j=0;j<M;j++){
            cin >> arr[i][j];
            if(arr[i][j]==1){
                //육지일 경우 큐에 담아둠
                q.push(make_pair(i,j));
            }
        }
    }
    int z=q.size();
    //큐에 담긴 육지들 확인
  for(i=0;i<z;i++){
    x= q.front().first;
    y=q.front().second;
   // cout <<x<< ","<< y<<" queue 접근\n";
    q.pop();
    if(arr2[x][y]==0){
   //     cout <<x<< ","<< y<<" queue 성공: dfs 실행\n";
        dfs(x,y);
        count1++;
    }
  }
    cout << count1 << '\n';
  } 
}