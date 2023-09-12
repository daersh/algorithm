#include <bits/stdc++.h>

using namespace std;

#define NUM 101000


int c[NUM];
vector<int> a[201000];
int N, M, V;
int b[NUM] = {0};

void dfs(int start){
    int i;
    //방문한 노드면 return
    if(c[start]) return;
    //처음 방문이면 방문으로 바꿈
    c[start]= true;

    for(i=0; i< a[start].size(); i++){
        int y=a[start][i];
        if(c[y] !=true){
            b[y]= b[start] +1;
            dfs(y);

        }

    }
}

int main(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> V;
    int i, x, y,j;
    memset(b, -1, sizeof(b));

    for(i=0;i<M;i++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    for(i=1;i<=N;i++){
        sort(a[i].begin(), a[i].end()); 
    }
    b[V]=0;
    dfs(V);

    for(i=1; i<= N;i++){
            cout << b[i]<< '\n'; 
    }

}