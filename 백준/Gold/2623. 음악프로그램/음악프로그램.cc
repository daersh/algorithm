#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n,m;

int main(){
    cin >> n >> m;
    int x,y;
    vector<int> vec[n+1];
    int arr[n+1];
    fill(&arr[0],&arr[n+1],0);
    for(int i=0; i < m; i++){
        cin >> x;
        int past=0;
        vector<int> in;
        for(int j=0;j<x;j++){
            cin >> y;
            if(j!=0)
                arr[y]+=j;

            in.push_back(y);
        }
        for(int j=0;j<in.size();j++){
            for(int k=j+1;k<in.size();k++){
                vec[in[j]].push_back(in[k]);
            }
        }

    }
    queue<int> q;
    for(int i=1; i<=n;i++){

        if(arr[i]==0){
            q.push(i);
        }
    }
    
    vector<int> result;
    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        // cout << val <<'\n';
        result.push_back(val);
        for(int i=0;i<vec[val].size();i++){
            int next= vec[val][i];
            arr[next]--;
            if(arr[next]==0){
                q.push(next);
            }
        }
    }
    if(result.size()!=n){
        cout << 0;
    }else {
        for(int i=0; i< result.size();i++){
            cout << result[i]<<'\n';
        }
    }
    
    
}
