#include <bits/stdc++.h>

using namespace std;
int N;
int M;
int arr[1000];
int visited[1000];
int arr2[1000];

void dfs(int x, int count){
    if(count==6){
        for(int i=0;i< 6;i++){
            cout << arr2[arr[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=x;i<=N;i++){
        if(visited[i]==false && arr2[i]!=0){
            visited[i]=true;
            arr[count]= i;
            dfs(i, count+1);
            visited[i]=false;
        }
    }

}


int main(){
    while(1){
    cin >> N;
    if(N==0){
        return 0;
    }
    for(int i=0;i<N;i++){
        cin >> arr2[i];
    }

    dfs(0,0);
    cout << '\n';
    }
}