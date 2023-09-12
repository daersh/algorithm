#include <bits/stdc++.h>


using namespace std;

void bfs();

int N, M;
int count1 = false;
vector<int> vec[2010];
int visited[2010];

void dfs(int x, int count){

    if(visited[x]==true) return;
    //cout << x <<" 방문 " << count << "개" << '\n';

    if(count==5){
        count1=true;
        return;
    }
    visited[x]=true;
    int z= vec[x].size();

    for(int i=0;i<z;i++){
        if(visited[vec[x][i]]!=true ){
            dfs(vec[x][i],count+1);
        }
    }
    visited[x]=false;
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int a=false;
    cin >> N >> M;
    int i;
    int x,y;
    for(i=0;i<M;i++){
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    for(i=0;i<N;i++){
        //cout<<'\n' << i << " 시작\n";
        fill_n(visited, sizeof visited/ sizeof visited[0],false);
        dfs(i,1);
        if(count1==true) {
            cout << 1;
            return 0;
        }
    }
    
    cout << 0;

    return 0;
  
}