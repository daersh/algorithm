#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int N;
queue<pii> q;
pii shark_position;
int arr[21][21];
int visited[21][21];

// 아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 
// 나머지 칸은 모두 지나갈 수 있다. 
// 아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다.
//  따라서, 크기가 같은 물고기는 먹을 수 없지만, 
// 그 물고기가 있는 칸은 지나갈 수 있다.

int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
            if(arr[i][j]==9){
                shark_position = make_pair(i,j);
            }
        }
    }

    q.push(shark_position);
    int cnt=0;
    while(!q.empty()){
        cnt++;
        int z=q.size();

        for(int k=0;k<z;k++){
            int x=q.front().first;
            int y= q.front().second;
            q.pop();
            if(visited[x][y]==true){
                continue;
            }
            visited[x][y]=true;
            


        }
    }
}
