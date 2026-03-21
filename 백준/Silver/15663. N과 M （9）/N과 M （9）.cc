#include <bits/stdc++.h>

using namespace std;
int N,M;

int arr[10];
int past[10];
int visited[10];
int result[10];

vector<int> vec[10000];

void dfs(int val, int cnt){
    int tf=false;
    if(cnt==M){
        int cmp_tf;
        for(int i=0; i<vec[result[0]].size(); i+=M){
            cmp_tf=M;
            for(int j=0;j<M;j++){
                if(result[j] == vec[result[0]][i+j]){
                   // cout << i+1<<" 중복\n";
                    cmp_tf--;
                    if(cmp_tf==0){
                        tf=true;
                    }
                }
            }
        }
        if(tf==true){
            return;
        }
       
        
        for(int i=0;i< M;i++){
            vec[result[0]].push_back(result[i]);
            cout << result[i] << ' ';
        }
        cout << '\n';
         return;
    }


    for(int i=1;i<=N;i++){
        if(visited[i]==false){
            
            visited[i]=true;
            result[cnt]= arr[i];
            dfs(val, cnt+1);
            visited[i]=false;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;

    for(int i=1; i<=N;i++) {
        cin >>arr[i];
    }
    sort(arr,arr+N+1);
;    dfs(0,0);

}