#include <bits/stdc++.h>

using namespace std;

#define NUM 100100

int c[NUM];
int b[NUM];
int count1=1;

void dfs(int start, vector<int> a[]){
    int i;
    //방문한 노드면 return
    if(c[start]) return;
    //처음 방문이면 방문으로 바꿈
    b[start] = count1;
    count1++;
    c[start]= true;
    for(i=a[start].size()-1;i>=0;i--){
        int y= a[start][i];
        if(c[y] !=true){
            
            dfs(y, a);
        }
    }
}

int main(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
    for(i =1; i<=N;i++){
        cout << b[i] << '\n';
    }
}