#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int visited[100010];

int main(){
    int n;
    cin >> n;
    vector<int> vec[n+1];
    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    
    queue<set<int>> q;
    bool flag =true;
    set<int> data;
    for(int i=0; i<vec[1].size();i++){
        data.insert(vec[1][i]);
    }
    q.push(data);
    visited[1]=true;
    int x;
    cin >>x;
    if(x!=1){
        flag=false;
    }
    queue<int> inserts;
    for(int i=1; i<n;i++){
        int x;
        cin>>x;
        inserts.push(x);
    }
    //입력 드오는거로 다음꺼 예측해야함 
    while(!q.empty()){
        set<int> data= q.front();
        // cout << "data: ";
        // for(int d : data){
            // cout << d<<' ';
        // }cout <<'\n';
        q.pop();
        for(int i=0;i<data.size();i++){
            
            int x = inserts.front();
            inserts.pop();
            
            visited[x]=true;
            if(data.find(x)==data.end()){
                flag=false;
                continue;
            }
            set<int> nexts;
            for(int j=0;j<vec[x].size();j++){
                if(visited[vec[x][j]])
                    continue;
                nexts.insert(vec[x][j]);
            }
            q.push(nexts);
        }
    }
    cout << flag;
}