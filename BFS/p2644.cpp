#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main(){
    int n;
    cin >> n;
    int s,e;
    cin >> s>>e;
    int m;
    cin >> m;
    vector<int> vec[n+1];
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    int cnt=1;
    queue<int> q;
    int visited[n+1];
    fill(&visited[0],&visited[n+1],0);
    q.push(s);
    while (!q.empty())
    {
        int z = q.size();
        for(int i=0; i< z;i++){
            int x= q.front();
            // cout << x <<'\n';
            q.pop();
            for(int j=0; j<vec[x].size();j++){
                if(visited[vec[x][j]]==0){
                    visited[vec[x][j]]=cnt;
                    q.push(vec[x][j]);
                }
            }
        }
        cnt++;
    }
    if(visited[e]==0)
        cout << -1;
    else 
        cout << visited[e];
}


/*

   6
  5 7
 4   8
3     9
*/