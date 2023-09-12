#include <bits/stdc++.h>

using namespace std;

long long N, M, K, X;

struct data{
    int val;
    int count;
}dada;

queue <struct data> q;
vector<int> vec[300200];
int visited[300200];
queue<int> result;

void bfs(){

    while(!q.empty()){
        
        int x = q.front().val;
        int y = q.front().count;
        int z = vec[x].size();
        
        q.pop();
        if(visited[x]==true) continue;
        visited[x]=true;
        if(y==K) { 
            result.push(x); 
            continue;
            }
        //cout << x << "값 | " << y <<"횟수 | "<<z<<"회 반복 \n";
        for(int i=0;i<z;i++){
                dada.val=vec[x].back();
                dada.count= y+1;
                vec[x].pop_back();
                q.push(dada);
        }
    }

}


int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

   cin >> N >> M >> K >> X;
    int x, y;
    for(int i=0;i<M;i++){
        cin >> x >> y;
        vec[x].push_back(y);
    }
    dada.val=X;
    dada.count=0;
    q.push(dada);
    bfs();

    int z = result.size();
    if(z==0){
        cout << -1;
        return 0;
    }
    int arr[z];
    for(int i=0;i<z;i++){
        arr[i]=result.front();
        result.pop();
    }
    sort(arr, arr+z);
    for(int i=0;i<z;i++){
        cout << arr[i] << '\n';
    }
    return 0;
}