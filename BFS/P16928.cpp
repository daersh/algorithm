#include <bits/stdc++.h>

using namespace std;

int N, M;
int up[110];
int visited[110];
int upcount;
queue<pair<int,int> > q;

void  bfs(){
    
    while(!q.empty()){

        int loc= q.front().first;
        int count= q.front().second;
        q.pop();
        if(loc >= 100 ){
            cout << count;
            return;
        }
        visited[loc]=true;

        if(up[loc]>0){
            q.push(make_pair(up[loc],count));
            continue;
        }
        for(int i=1; i<=6;i++){
            if(up[loc+i]>0){
                q.push(make_pair(up[loc+i],count+1));
            }else if(visited[loc+i]!=true){
                q.push(make_pair(loc+i,count+1));
            }
        }

    }
}


int main(){
    cin >> N >> M;
    int i;
    int insert1, insert2;
    for(i=0;i<N+M;i++){
        cin >>  insert1 >> insert2;
        up[insert1] = insert2;
    }
    q.push(make_pair(1,0));
    bfs();


}