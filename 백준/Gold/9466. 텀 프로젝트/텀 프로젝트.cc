#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
int cnt;
int arr[100010];
int visited[100010];
int m[100010];


int dfs(int loc,int c, int *m){
// 2 1
// 3 2
// 1 3
// visited[2] == true
// c- m[2] 
// 4 - 1
    // cout << m[loc]<<'\n';
    if(visited[loc]){
        int past_loc = m[loc];
        if(past_loc ==0){
            m[loc]=0;
            return 0;
        }
        // cout << c << " " << past_loc << "= "<< c-past_loc <<'\n';
        m[loc]=0;
        return c-past_loc;
    }
    m[loc] = c;
    visited[loc] = true;
    int x = dfs(arr[loc],c+1,m);
    
    m[loc]=0;

    return x;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T;
    cin >> T;

    for(int t=0;t<T;t++) {
        int n;
        cin >> n;
        int result=n;
        
        fill(&visited[0],&visited[n+1],false);

        for(int i=1;i<=n;i++) {
            cin >> arr[i];
            // 자기 자신인 경우 미리 제외
            // if(arr[i]==i) {
                // visited[i] = 2;
                // result--;
            // }
        }
        
        // 1. 자기 자신만 가리키는 경우
        // 2. 순환일때
        for(int i=1; i <=n; i++){
            if (visited[i]) continue;
            int x = dfs(i,1,m);
            result-=x;
            // cout <<"result = " << result << '\n';
        }

        cout << result << '\n';
    }
}
//1
//7
//3 1 3 7 3 4 6

//1
// 5
// 5 5 4 5 3