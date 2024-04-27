#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int INF= 1e9;
typedef pair<int,int> pii;
 
 
 int xn[2] = {1,0};
 int yn1[2] = {0,1};
 int visited[1010][1010];
 struct Node{
    int x;
    int y;
    int v;
    Node(int x, int y, int v){
        this->x = x;
        this->y = y;
        this->v = v;
    }
 };
 
int main(){
    	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n , m ;
    cin >> n >> m;

    int arr[n][m];
    for(int i=0; i< n; i++){
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
            arr[i][j]= x;
            visited[i][j] = -1;
         }
    }
    int p;
    cin >> p;
 
    Node loc = Node(0,0,p-arr[0][0]);
    queue<Node> q;
    q.push(loc);
 
    int result= -1;
 
    while(!q.empty()){

        int x = q.front().x;
        int y = q.front().y;
        int p = q.front().v;
        q.pop();
        
        if(p < visited[x][y]) continue;
        
        if(x== n-1 && y== m-1){
            if(p > result)
                result = p;
            continue;
        }
 
        for(int i=0; i<2;i++){
            int next_x = x+xn[i];
            int next_y = y+yn1[i];
            if(next_x<0 || next_x>= n || next_y <0 || next_y>= m || arr[next_x][next_y]> p  ) continue;
            if(visited[next_x][next_y] >= p-arr[next_x][next_y] ){
                continue;
            }
            loc = Node(next_x,next_y,p-arr[next_x][next_y]);
            visited[next_x][next_y] = p-arr[next_x][next_y];
            q.push(loc);
        }
 
    }
    if(result>=0){
        cout << "YES" << '\n' << p-result;
    }else {
        cout << "NO";
    }
    return 0;
}