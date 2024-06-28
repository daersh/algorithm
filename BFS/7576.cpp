#include <bits/stdc++.h>

using namespace std;

#define NUM 1010

int arr[NUM][NUM];

int c[NUM][NUM];
int b[NUM][NUM];
int count1=1;
    int N, M, V;

void dfs(int start, int end){
    int i;    
    if(c[start][end]) return;

    c[start][end]= true;


    if(start+1!=M  && arr[start+1][end] ==0) dfs(start+1,end);
    if(start != 0  && arr[start-1][end] ==0 ) dfs(start-1,end);
    if(end+1!=N && arr[start][end+1] ==0 ) dfs(start,end+1);
    if(end != 0 && arr[start][end-1] ==0 ) dfs(start,end-1);

}

int main(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    int i, x, y,j;

    vector<int> a[N+1];

    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    
    int sum;

    while(1){
        count1++;
        sum=0;
        for(i=0;i<=M;i++){
            for(j=0;j<=N;j++){
                if(arr[i][j]==1){
                        dfs(i,j);
                        sum+=1;
                        if(sum== M*N){
                            break; 
                        }
                }
            }
            if(sum== M*N){
            break; 
            }
        }

    }

}
