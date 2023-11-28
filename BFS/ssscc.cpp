#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n =7;

    vector<int> vec[n+1];
    int x,y;
    for(int i=0;i<n;i++){
        cin >> x >>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    
    int answer = 0;
    
    int dist[n+1];
    fill(&dist[0],&dist[n+1],100000000);
    queue<pair<int,int> > q;
    dist[1]=0;
    q.push(make_pair(1,0));
    while(!q.empty()){
        int l = q.front().first;
        int d = q.front().second;
        q.pop();
        if(d>dist[l])continue;
        
        for(int i=0; i<vec[l].size();i++){
            int ll = vec[l][i];
            
            if(d+1 < dist[ll]){
                dist[ll]=d+1;
                q.push(make_pair(ll,dist[ll]));
            }
        }
    }
    for(int i=1;i<n;i++){
        cout << dist[i]<<'\n';
    }
    int max_val=0;
    for(int i =1; i<=n;i++){
        if(dist[i]>max_val){
            max_val= dist[i];
            answer=1;
        }else if(dist[i]==max_val){
            answer++;
        }
    }
    
    return answer;
}