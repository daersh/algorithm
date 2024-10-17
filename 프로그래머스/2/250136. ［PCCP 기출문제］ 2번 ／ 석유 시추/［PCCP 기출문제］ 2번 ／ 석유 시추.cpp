#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
vector<vector<int> > vec;

int n,m;
int visited[510][510];
int flag=1;
int visited2[510][510];
map<int,int> mmm;


int xn[4] = {0,0,-1,1};
int yn[4] = {1,-1,0,0};


void solve(){
    
    int val =0;
    for(int i =0; i < n;i++)
        for(int j =0;j<m;j++)
            visited[i][j]=0;
    
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(!visited[i][j] && vec[i][j]){
                queue<pair<int,int> > update;
                queue<pair<int,int> > q;
                int value = 1;
                q.push({i,j});
                visited[i][j]++;
                update.push({i,j});
                
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    for(int k =0;k<4;k++){
                        int xx = x+xn[k];
                        int yy = y+yn[k];
                        if(xx<0||yy<0||xx>=n||yy>=m||visited[xx][yy]||!vec[xx][yy])
                            continue;
                        visited[xx][yy]++;
                        update.push({xx,yy});
                        q.push({xx,yy});
                        value++;
                    }
                }
                
                while(!update.empty()){
                    visited2[update.front().first][update.front().second]= flag;
                    update.pop();
                }
                mmm[flag]=value;
                flag++;
            }
        }
    }
    
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    vec=land;
    n= land.size();
    m= land[0].size();
    

    solve();
    
    for(int i =0;i<m;i++){
        int val=0;
        set<int> visit;
        
        for(int j=0;j<n;j++){
            
            if(visit.find(visited2[j][i]) == visit.end() ){
                val += mmm[visited2[j][i]];
                visit.insert(visited2[j][i]);
            }
        }
        
        answer = max(val,answer);
    }
    
    
    return answer;
}