#include <bits/stdc++.h>

using namespace std;

int N;
int visited[100];
int answer=0;
int arr[100];
void dfs(int x, int cnt){

    if(cnt==N){
        cout << x<<" 도달 \n";
        answer++;
        return;
    }

    if(x==0){
        for(int i=1;i<=N;i++){
            arr[1]=i;
            visited[i]=true;
            cout << i <<'\n';
            dfs(i,1);
            arr[1]=10000;
            visited[i]=false;
        }

        return;
    }

    for(int i=1; i<=N; i++)
    {
        if( visited[i]==false)
        {
            int c = x-i;
            if(c<0){
                c=i-x;
            }

            if(c>=2)
            {
                arr[cnt+1]=i;
                int truefalse=false;
                
                for(int j=1; j<=cnt; j++){
                    if(arr[j]+j == arr[cnt+1]+i
                        || arr[j]-j == arr[cnt+1] -i  ){
                        truefalse=true;
                    } 
                }

                if(truefalse==true){
                    continue;
                }
                cout << x <<" to " << i <<"이동, count= "<<cnt <<'\n';
                visited[i]=true;
                dfs(i,cnt+1);
                arr[cnt+1]=10000;
                visited[i]=false;

            }
        }

    }
    
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> N;

    dfs(0,0);
    
    cout << answer;
    return 0;
}