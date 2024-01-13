#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[8][8];
int next_x[4]= {0,0,1,-1};
int next_y[4]= {1,-1,0,0};
int visited[8][8];
int n,m;
int result; 
void bfs(){
    for(int i=0; i< n;i++){
        fill(&visited[i][0],&visited[i][m],0);
    }
    queue<pair<int,int> > q;
    for(int i=0; i< n;i++){
        for(int j=0;j<m;j++){

            if(arr[i][j]==2){

                q.push(make_pair(i,j));

                while (!q.empty())
                {
                    int x= q.front().first;
                    int y= q.front().second;
                    q.pop();
                    if(visited[x][y]==1) continue;
                    visited[x][y]=1;
                    for (int i = 0; i < 4; i++)
                    {
                        int x_new = x+next_x[i];
                        int y_new = y+next_y[i];
                        
                        if(x_new>=0 && y_new>=0 && x_new<n && y_new<m 
                            && visited[x_new][y_new]== 0
                            && arr[x_new][y_new]==0 ){
                            q.push(make_pair(x_new,y_new));
                        }
                    }
                    
                }
            }
        }
    }
    int cnt=0;
    for(int i=0; i< n;i++){
        for(int j=0; j<m;j++){
            if(!visited[i][j]&& arr[i][j]==0) cnt++;
        }
    }
    if(cnt> result){
        result=cnt;
        // cout << result <<' ';

    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i< n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    //64 * 64 * 64 
    for(int x1=0;x1<n;x1++){
        for(int y1=0;y1<m;y1++){
            if(arr[x1][y1]!=0) continue;
            arr[x1][y1]=1;

            for(int x2=0;x2<n;x2++){
                for(int y2=0;y2<m;y2++){
                    if(arr[x2][y2]!=0) continue;
                    arr[x2][y2]=1;

                    for(int x3=0;x3<n;x3++){
                        for(int y3=0;y3<m;y3++){

                            if(arr[x3][y3]!=0) continue;
                            arr[x3][y3]=1;
                            bfs();
                            arr[x3][y3]=0;
                        }
                    }
                    arr[x2][y2]=0;
                }
            }
            arr[x1][y1]=0;
        }
    }
    cout << result;
}