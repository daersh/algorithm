#include <bits/stdc++.h>

using namespace std;

// 가로 세로
int M, N;

// data 저장
char arr[101][101];
// 방문한 노드인지 확인
int red_visited[101][101];
int blue_visited[101][101];
int green_visited[101][101];
int redgreen_visited[101][101];
int visited2[101][101];

//dfs 돌 큐들
//red
queue<pair<int, int> > red;
//blue
queue<pair<int, int> > blue;
//green
queue<pair<int, int> > green;
//red+green
queue<pair<int, int> > redgreen;

void dfs_red(int x, int y){
  red_visited[x][y]=true;
  if(x!=0 && red_visited[x-1][y]==false && arr[x-1][y]== 'R'){
    dfs_red(x-1,y);
  }
  if(x!=N-1 && red_visited[x+1][y]==false && arr[x+1][y]== 'R'){
    dfs_red(x+1,y);
  }
  if(y!=0 && red_visited[x][y-1]==false && arr[x][y-1]== 'R'){
    dfs_red(x,y-1);
  }
  if(y!=M-1 && red_visited[x][y+1]==false && arr[x][y+1]== 'R'){
    dfs_red(x,y+1);
  }
  
}

void dfs_blue(int x, int y){
  blue_visited[x][y]=true;
  if(x!=0 && blue_visited[x-1][y]==false && arr[x-1][y]== 'B'){
    dfs_blue(x-1,y);
  }
  if(x!=N-1 && blue_visited[x+1][y]==false && arr[x+1][y]== 'B'){
    dfs_blue(x+1,y);
  }
  if(y!=0 && blue_visited[x][y-1]==false && arr[x][y-1]== 'B'){
    dfs_blue(x,y-1);
  }
  if(y!=M-1 && blue_visited[x][y+1]==false && arr[x][y+1]== 'B'){
    dfs_blue(x,y+1);
  }
}

void dfs_green(int x, int y){
  green_visited[x][y]=true;
  if(x!=0 && green_visited[x-1][y]==false && arr[x-1][y]== 'G'){
    dfs_green(x-1,y);
  }
  if(x!=N-1 && green_visited[x+1][y]==false && arr[x+1][y]== 'G'){
    dfs_green(x+1,y);
  }
  if(y!=0 && green_visited[x][y-1]==false && arr[x][y-1]== 'G'){
    dfs_green(x,y-1);
  }
  if(y!=M-1 && green_visited[x][y+1]==false && arr[x][y+1]== 'G'){
    dfs_green(x,y+1);
  }
}

void dfs_redgreen(int x, int y){
  redgreen_visited[x][y]=true;

  if(x!=0 && redgreen_visited[x-1][y]==false){
    if(arr[x-1][y]== 'G' || arr[x-1][y]== 'R'){
      dfs_redgreen(x-1,y);
    }
  }
  if(x!=N-1 && redgreen_visited[x+1][y]==false){
    if(arr[x+1][y]== 'G' || arr[x+1][y]== 'R'){
      dfs_redgreen(x+1,y);
    }
  }
  if(y!=0 && redgreen_visited[x][y-1]==false){
    if(arr[x][y-1]== 'G' || arr[x][y-1]== 'R'){
      dfs_redgreen(x,y-1);
    }
  }
  if(y!=M-1 && redgreen_visited[x][y+1]==false){
    if(arr[x][y+1]== 'G' || arr[x][y+1]== 'R'){
      dfs_redgreen(x,y+1);
    }
  }
}

int main(){
  int i, j;
  int x, y;
  cin >> M;
  
  for(i=0; i<M; i++){
    string a;
		cin >> a;
		for (int j = 0; j < M; j++) {
			arr[i][j] = a[j];
		
        if(arr[i][j]=='R'){
          //육지일 경우 큐에 담아둠
          red.push(make_pair(i,j));
        }else if(arr[i][j]=='B'){
          //육지일 경우 큐에 담아둠
          blue.push(make_pair(i,j));
        }else if(arr[i][j]=='G'){
          //육지일 경우 큐에 담아둠
          green.push(make_pair(i,j));
        }
        if(arr[i][j]=='G' || arr[i][j]=='R'){
          //육지일 경우 큐에 담아둠
          redgreen.push(make_pair(i,j));
        }
    }
  }
  int red_count = 0;
  int blue_count = 0;
  int green_count = 0;
  int redgreen_count = 0;
  while(!red.empty()){
    int x= red.front().first;
    int y= red.front().second;
    red.pop();
    if(red_visited[x][y]==true){
      continue;
    }
    red_count++;
    dfs_red(x,y);
  }
  while(!blue.empty()){
    int x= blue.front().first;
    int y= blue.front().second;
    blue.pop();
    if(blue_visited[x][y]==true){
      continue;
    }
    blue_count++;
    dfs_blue(x,y);
  }
  while(!green.empty()){
    int x= green.front().first;
    int y= green.front().second;
    green.pop();
    if(green_visited[x][y]==true){
      continue;
    }
    green_count++;
    dfs_green(x,y);
  }

  while(!redgreen.empty()){
    int x= redgreen.front().first;
    int y= redgreen.front().second;
    redgreen.pop();
    if(redgreen_visited[x][y]==true){
      continue;
    }
    
    redgreen_count++;
    dfs_redgreen(x,y);
  }

  //cout << "red: "<< red_count;
  //cout << "\nblue "<< blue_count;
  //cout << "\ngreen " << green_count;
  //cout << "\nredgreen "<< redgreen_count;
  cout <<red_count+green_count+blue_count <<' '
  << redgreen_count+ blue_count;
}