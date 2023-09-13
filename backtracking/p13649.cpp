#include <bits/stdc++.h>

using namespace std;
int N;
int M;
int arr[1000];
int visited[1000];


void dfs(int x, int count){

    if(count==M){
        for(int i=0;i< M;i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1;i<=N;i++){
        if(visited[i]==false){
            visited[i]=true;
            arr[count]= i;
            dfs(i+1, count+1);
            visited[i]=false;
        }
    }

}


int main(){

    cin >> N >> M;
    dfs(1,0);

}