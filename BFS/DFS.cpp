#include <bits/stdc++.h>

using namespace std;

#define NUM 1010

int number = NUM;
int c[NUM];
int b[NUM];


void dfs(int start, vector<int> a[]){
    int i;
    //방문한 노드면 return
    if(c[start]) return;
    //처음 방문이면 방문으로 바꿈
    c[start]= true;
    cout << start << ' ';
    for(i=0;i<a[start].size();i++){
        int y= a[start][i];
        dfs(y, a);
    }
}

void bfs(int start, vector<int> a[]){
    int i;
    queue<int> q;
    q.push(start);

    b[start] = true;

    while(!q.empty()){

        int x= q.front();
        q.pop();
        printf("%d ",x);

        for(i=0;i<a[x].size();i++){
            int y= a[x][i];
            if(!b[y]){
                q.push(y);
                b[y]= true;
            }
        }
    }
}

int main(){

    int N, M, V;
    cin >> N >> M >> V;
    int i, x, y;

    vector<int> a[N+1];

    for(i=0;i<M;i++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    for(int i=1;i<=N;i++){
        sort(a[i].begin(), a[i].end());
    }

    dfs(V, a);
    cout << '\n';
    bfs(V, a);

}
