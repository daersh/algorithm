#include <bits/stdc++.h>

using namespace std;
int N;
int M;
int arr[100][100];
int arr2[1000];
int result= 10000000;
int visited[100][100];
int val;

void dfs(int x,int y, int count){

    printf("    [%d, %d]       val: %d      count: %d\n",x,y,val, count);

    if(count==M){
        
        if(val < result){
            result = val;
        }
        cout <<"result: " <<result << '\n';
        return;
    }

    for(int j=1;j<=N;j++){
        for(int i=1;i<=N;i++){
            if(visited[j][i]==false){
                visited[j][i]=true;
                //arr[count]= i;
                if(count ==1 ){
                    val= 0;
                }
                val +=arr[j][i];
                

                dfs(j, i, count+1);
                visited[j][i]=false;
            }
        }
    }
}

int main(){

    
    cin >> N ;
    M=N/2;
    int i,j;
    int cnt = 0;
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            cin >> arr[i][j];
            if(j==i){
                visited[i][j]=true;
            }
        }
    }
    dfs(1,1,cnt);
    

}