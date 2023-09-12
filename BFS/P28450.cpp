#include <bits/stdc++.h>


using namespace std;
#define used 1
#define notused 0

// 가로 세로
int M, N;
// data 저장
int arr[1100][1100];
int arr2[1100][1100];
int V;
int number = 1;
int visited[1100][1100];

int dp(int x, int y){
  if(visited[x][y] == true) return arr2[x][y];
  visited[x][y] = true;

  if(x>0 && y>0)
    arr2[x][y]= min(dp(x-1,y) , dp(x,y-1)) + arr[x][y];
    
  else if(x==0 && y>0){
    arr2[x][y] = dp(x,y-1)+ arr[x][y];
  }else if(y==0 && x>0){
    arr2[x][y]= dp(x-1,y)+arr[x][y];
  }

  return arr2[x][y];

}

int main(){    
  ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
  int i, j;
  int x, y;
  cin >> N >> M;
  for(i=0; i<N; i++){
    for(j=0;j<M;j++){
      cin >> arr[i][j];
    }
  }
  cin >> V;
  arr2[0][0] = arr[0][0];
  dp(N-1,M-1);  

  if(V >= arr2[N-1][M-1])
    cout << "YES\n"<<arr2[N-1][M-1];
  else 
    cout << "NO";
}

