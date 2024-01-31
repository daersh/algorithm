#include <bits/stdc++.h>

using namespace std;


int c[51][51];
int arr[51][51];
int N, M, V;


void dfs(int x, int y) {
  int i;
  //방문한 노드면 return
  if (c[x][y]==true)
    return;

  //처음 방문이면 방문으로 바꿈
  c[x][y] = true;

  
  if (arr[x - 1][y] == 1)
    dfs(x-1, y);
  if (arr[x + 1][y] == 1)
    dfs(x+1, y);
  if (arr[x][y + 1] == 1)
    dfs(x, y+1);
  if (arr[x][y - 1] == 1)
    dfs(x, y-1);

}

int main() {
  int NUM;
  cin >> NUM;

  for(int z=0; z<NUM; z++){

    cin >> N >> M >> V;

    int i, x, y;

    for (i = 0; i < V; i++) {

        cin >> x >> y;
        arr[x+1][y+1] = 1;
    }
    int count = 0;


    for (i = 0; i < N + 1; i++) {
        for (int j = 0; j < M + 1; j++) {

            if (arr[i][j] == 1 && c[i][j]== false) {
                count++;
                dfs(i, j);
            }

        }   
    }

    cout << count << '\n';

    memset(arr,0,sizeof(arr));
    memset(c,0,sizeof(c));

    }

}