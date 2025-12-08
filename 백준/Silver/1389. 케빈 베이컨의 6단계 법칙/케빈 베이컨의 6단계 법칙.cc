#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n , m;
    cin >> n >> m;
    vector<int> vec[n+1];
    int a,b;
    for(int i=0; i< m;i++){
        cin >> a >>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    int result_val= 1e9;
    int result_loc=-1;
    for(int i=1; i<= n; i++){
        vector<bool> visit;
        visit.resize(n+1);
        queue<int> q;
        q.push(i);
        int cnt=0;
        int asdf=1;
        while (!q.empty()){
            int size =q.size();
            for(int j=0; j<size;j++){
                int v= q.front();
                q.pop();
                if(visit[v]) continue;
                visit[v]=true;
                for(int k=0;k<vec[v].size();k++){
                    int vv = vec[v][k];
                    if(visit[vv]) continue;
                    q.push(vv);
                    cnt+=asdf;
                }
            }
            asdf++;
        }
        if(result_val > cnt){
            // cout << i<< " cnt: " << cnt<< '\n';
            result_val= cnt;
            result_loc= i;
        }
    }
    cout << result_loc;
}