#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while (t!=0)
    {
        t--;
        int n,m;
        cin >> n >>m;
        int arr[n+1];
        int arr2[n+1];
        vector<int> vec[n+1];

        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            arr[i]=x;
            arr2[i]=0;
        }

        for(int i=0; i<m;i++){
            int x,y;
            cin >> x>>y;
            vec[x].push_back(y);
            arr2[y]++;
        }

        queue<int> q;

        int visited[n+1];
        fill(&visited[0],&visited[n+1],0);
        for(int i=1;i<=n;i++){
            if(arr2[i]==0)q.push(i);
        }
        int max=0;
        while (!q.empty())
        {
            int loc = q.front();
            arr[loc]+=visited[loc];
            if(max<arr[loc]) max=arr[loc];
            q.pop();
            for(int i=0;i<vec[loc].size();i++){
                int next=vec[loc][i];
                arr2[next]--;
                if(visited[next]<arr[loc]){
                    visited[next]=arr[loc];
                }
                if(arr2[next]==0) q.push(next);
            }
        }
        // for(int i=1; i<=n;i++){
        //     cout << arr[i]<<' ';
        // }cout <<'\n';
        int end_point;
        cin >> end_point;
        cout << arr[end_point]<<'\n';
    }
    
}