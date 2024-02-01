#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int INF = 1e9;

struct Node{
    int x;
    int y;
    int d;
    int wall;
    Node(int x, int y, int d,int wall){
        this->x = x;
        this->y = y;
        this->d = d;
        this->wall = wall;
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n ,m,k; // 세로,가로, 부술 수  있는 벽cnt
    cin >> n >> m >> k;
    int arr[n][m];
    int visited[k+1][n][m];
    
    for(int i=0; i< n; i++){
        string x;
        cin >> x;
        for(int j=0;j<m;j++){
            arr[i][j]= x[j]-48;
        }
    }
    for(int j=0;j<=k;j++)
        for(int i=0; i< n;i++)
            for(int z=0;z<m;z++){
                visited[j][i][z]=false;
            }
    
    // cout <<"--arr--\n";
    // for(int i=0; i< n; i++){
    //     for(int j=0; j< m; j++){
    //         cout << arr[i][j];
    //     }cout <<'\n';
    // }
    
    queue<Node> q;
    
    q.push(Node(0,0,0,k));

    int x_new[4]= {0,0,1,-1};
    int y_new[4]= {1,-1,0,0};
    int result=INF;
    while (!q.empty())
    {
        Node node = q.front();
        
        int x= node.x;
        int y= node.y;
        int d= node.d;
        int wall = node.wall;
        q.pop();
        if(x==n-1 && y==m-1 &&result>d){
            result=d;
        }
        if(visited[k-wall][x][y]==true) continue;
        visited[k-wall][x][y]=true;
        // cout<< x<<' '<< y<<' '<<d<<' '<<wall<<'\n';
        for(int i=0;i<4;i++){
            int x_next= x+x_new[i];
            int y_next= y+y_new[i];
            // cout << x_next<<' '<<y_next<<'\n';

            if(x_next>= 0 && x_next<n && y_next>= 0 && y_next<m){
                if(arr[x_next][y_next]!=0 && wall!=0){
                    // cout << " push!!\n";
                    q.push(Node(x_next,y_next,d+1,wall-1));
                }
                if(arr[x_next][y_next]==0){
                    // cout<< " push!\n";
                    q.push(Node(x_next,y_next,d+1,wall));
                }
            }

        }

    }
    if(result==INF) cout <<-1;
    else cout << result+1;
}