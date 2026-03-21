#include <bits/stdc++.h>

using namespace std;
int N;
int M;
int arr[1000];
int visited[1000];
int arr2[1000];

void dfs(int x, int count){
    if(count==M){
        for(int i=0;i< M;i++){
            cout << arr2[arr[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=0;i<=N;i++){
        if(visited[i]==false && arr2[i]!=0){
            visited[i]=true;
            arr[count]= i;
            dfs(i+1, count+1);
            visited[i]=false;
        }
    }

}


int main(){

    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> arr2[i];
    }

    sort(arr2,arr2+N);
    dfs(0,0);

}