#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> pii;

int vec[110][110];
int visited[110][110];
int result;

int xn1[4] = {1,-1,0,0};
int yn1[4] = {0,0,1,-1};

int bfs(int s1,int s2){
    queue<pii> q;
    q.push(make_pair(s1,s2));

    int cnt = 0;
    
    while(!q.empty()){
        cnt++;
        int qsize = q.size();
        
        for(int i=0; i< qsize;i++){
            int x= q.front().first;
            int y= q.front().second;
            q.pop();
            
            if(visited[x][y]) continue;    
            visited[x][y]=cnt;
            
            for(int i=0; i< 4 ; i++){
                int xn = xn1[i]+x;
                int yn = yn1[i]+y;
                
                if(xn<0 || yn<0 || xn>= s1+1 || yn >= s2+1 || vec[xn][yn]==0 ) 
                    continue;
                
                q.push(make_pair(xn,yn));
            }
        }
        
    }
    result = visited[0][0]>1 ? visited[0][0] : -1;
    return result;
}


int solution(vector<vector<int> > maps)
{
    int x = maps.size();
    int y = maps[0].size();
    
    for(int i=0; i< x;i++){
        for(int j=0;j<y;j++){
            vec[i][j] = maps[i][j];
        }
    }
    
    result = bfs(x-1,y-1);
    
    return result;
}