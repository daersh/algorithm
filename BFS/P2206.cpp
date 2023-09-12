#include <bits/stdc++.h>

using namespace std;
#define used 1
#define notused 0

// 가로 세로
int M, N;
// data 저장
int arr[1100][1100];
int visited[1100][1100];
int result;

struct location {
  int x;
  int y;
  int wall_break;
} loca;

//위치, 카운트, 벽넘었는지
queue<pair<struct location, int>> q;

// 1 담아봄
queue<struct location> wall;

void bfs() {
  while (!q.empty()) {
    int x = q.front().first.x;
    int y = q.front().first.y;
    int count = q.front().second;
    q.pop();
    if (visited[x][y])
      continue;

    if (x == N - 1 && y == M - 1) {

      if (result == 0)
        result = count;
      else if (result != 0) {
        if (result > count) {
          result = count;
        }
      }
    }

    visited[x][y] = true;

    if (x < N - 1 && visited[x + 1][y] != true && arr[x + 1][y] == 0) {
      loca.x = x + 1;
      loca.y = y;
      q.push(make_pair(loca, count + 1));
    }

    if (y < M - 1 && visited[x][y + 1] != true && arr[x][y + 1] == 0) {
      loca.x = x;
      loca.y = y + 1;
      q.push(make_pair(loca, count + 1));
    }

    if (x > 0 && visited[x - 1][y] != true && arr[x - 1][y] == 0) {
      loca.x = x - 1;
      loca.y = y;
      q.push(make_pair(loca, count + 1));
    }

    if (y > 0 && visited[x][y - 1] != true && arr[x][y - 1] == 0) {
      loca.x = x;
      loca.y = y - 1;
      q.push(make_pair(loca, count + 1));
    }
    
  }
}

int main() {
  int i, j;
  int x, y;
  cin >> N >> M;
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      scanf("%1d", &arr[i][j]);
      if (arr[i][j] == 1) {
        loca.x = i;
        loca.y = j;
        wall.push(loca);
      }
    }
  }

  loca.x = 0;
  loca.y = 0;
  q.push(make_pair(loca, 1));
  bfs();
  

  while (wall.empty() == false) {
    x = wall.front().x;
    y = wall.front().y;
    wall.pop();
    if (x != 0 && x != N - 1 && arr[x - 1][y] == 0 && arr[x + 1][y] == 0) {
      memset(visited, 0, sizeof(visited));
      arr[x][y] = 0;
      loca.x = 0;
      loca.y = 0;
      q.push(make_pair(loca, 1));
      
      
    }
    if (y != 0 && y != M - 1 && arr[x][y - 1] == 0 && arr[x][y + 1] == 0) {
      memset(visited, 0, sizeof(visited));
      arr[x][y] = 0;
      loca.x = 0;
      loca.y = 0;
      q.push(make_pair(loca, 1));
      
    }
    if (x != 0 && y != M - 1 && arr[x - 1][y] == 0 && arr[x][y + 1] == 0) {
      memset(visited, 0, sizeof(visited));
      arr[x][y] = 0;
      loca.x = 0;
      loca.y = 0;
      q.push(make_pair(loca, 1));
    }

    if (y != 0 && x != N - 1 && arr[x + 1][y] == 0 && arr[x][y - 1] == 0) {
      memset(visited, 0, sizeof(visited));
      arr[x][y] = 0;
      loca.x = 0;
      loca.y = 0;
      q.push(make_pair(loca, 1));
    }

    arr[x][y] = 1;
  }

  if (result == 0) {
    cout << -1;
  } else {
    cout << result;
  }
}
