#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int arr[51][51];
int visited[51][51];
int n, m;

void bfs(int i, int j){
    queue<pair<int,int> > q;
    q.push(make_pair(i,j));
    while (!q.empty())
    {
        int x= q.front().first;
        int y= q.front().second;
        q.pop();
        if(visited[x][y]==1) continue;
        visited[x][y]=1;
        int x_new[4]= {1,-1,0,0};
        int y_new[4]= {0,0,1,-1};
        for(int i=0;i<4;i++){
            int xval = x_new[i]+x;
            int yval = y_new[i]+y;
            if(xval>=0 && yval>=0 && xval<n && yval<m ){
                if(visited[x][y]==0){
                    q.push(make_pair(xval,yval));
                }
            }
        }
    }
}

int max= 0;
struct Node{
    int x,y;
    int dist;
};

struct compare{
    bool operator()(const Node& s1, const Node& s2){
        return s1.dist > s2.dist;
    }
};
int xnew[4]= {1,-1,0,0};
int ynew[4]={0,0,1,-1};

int dig(int x, int y){
    priority_queue<Node,vector<Node>,compare> pque;
    Node node;
    int cmp[50][50];
    for(int i=0;i<50;i++){
        fill(&cmp[i][0],&cmp[i][50],1e9);
    }
    cmp[x][y]=0;
    node.x=x;
    node.y=y;
    node.dist=0;
    pque.push(node);
    int max=0;
    while (!pque.empty())
    {
        int dd= pque.top().dist;
        int x=  pque.top().x;
        int y= pque.top().y;
        pque.pop();
        if(dd>cmp[x][y]) continue;

        for(int i=0;i<4;i++){
            int xx=x+xnew[i];
            int yy=y+ynew[i];
            if(xx>=0&&xx<n&&yy>=0&&yy<m && arr[xx][yy]!=1){
                int ddd= 1;
                if(dd+ddd<cmp[xx][yy]){
                    cmp[xx][yy]=dd+ddd;

                    if(dd+ddd>max)max=dd+ddd;
                    node.dist=cmp[xx][yy];
                    node.x=xx;
                    node.y=yy;
                    pque.push(node);
                }
            }
        }
    }
    
    return max;
}

int main(){
    cin >> n>>m;


    for(int i=0; i< n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            if(s[j]=='W'){
                arr[i][j]=1;
                visited[i][j]=2;
            }else{
                arr[i][j]=0;
            }
        }  
    }
    int max= 0;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(arr[i][j]==0 && visited[i][j]==0){
                int cmp = dig(i,j);
                if(max<cmp) 
                    max=cmp;
            }
        }
    }
    cout << max;
}