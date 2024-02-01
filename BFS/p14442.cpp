#include <iostream>
#include <queue>
#include <vector>

using namespace std;


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
    int n ,m,k; // 세로,가로, 부술 수  있는 벽cnt
    cin >> n >> m >> k;
    int arr[n][m];
    int visited[n][m];
    for(int i=0; i< n; i++){
        string x;
        cin >> x;
        for(int j=0;j<m;j++){
            arr[n][j]= x[i];
        }
    }
    for(int i=0; i< n;i++)
        fill(&visited[i][0],&visited[i][m],-1);
    queue<Node> q;
    
    q.push(Node(0,0,0,k));

    int x_new[4]= {0,0,1,-1};
    int y_new[4]= {1,-1,0,0};

    while (!q.empty())
    {

        Node node = q.front();
        
        int x= node.x;
        int y= node.y;
        int d= node.d;
        int wall = node.wall;
        q.pop();
        // if(visited[x][y]<=wall || visited[x][y]!=0) continue;
        if(visited[x][y]>-1 && visited[x][y]<wall ){
            continue;
        }
        cout<< x<<' '<< y<<' '<<d<<' '<<wall<<'\n';
        visited[x][y]=wall;

        for(int i=0;i<4;i++){
            int x_next= x+x_new[i];
            int y_next= y+y_new[i];
            if(x_next>=0 && x_next<n && y_next>=0 && y_next<m){
                if(arr[x_next][y_next]==1 && wall!=0){
                    q.push(Node(x_next,y_next,d+1,wall-1));
                }else if(arr[x_next][y_next]==0)
                    q.push(Node(x_next,y_next,d+1,wall));
            }
        }
    }
    

}