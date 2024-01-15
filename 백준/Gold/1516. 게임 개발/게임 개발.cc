#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    // 비용
    int arr[n+1];
    // 위상
    int arr2[n+1];
    vector<int> vec[n+1];

    for(int i=0;i<=n;i++){
        arr2[i]=0;
    }
    
    for(int i=1; i<=n;i++){
        int x,y;
        cin >> x;
        arr[i]=x;
        while(1)
        {
            cin >> y;
            if(y==-1) break;
            vec[y].push_back(i);
            arr2[i]++;
        }

    }

    queue<int> q;
    int visited[n+1];
    fill(&visited[0],&visited[n+1],0);
    
    for(int i=1;i<=n;i++){
        if(arr2[i]==0) q.push(i);
    }

    while (!q.empty())
    {
        
        int loc = q.front();
        // cout <<"loc: "<<loc<<'\n';
        arr[loc]+=visited[loc];
        q.pop();

        for(int i=0; i< vec[loc].size();i++){
            int next= vec[loc][i];
            arr2[next]--;

            if(visited[next]<arr[loc]){
                visited[next]=arr[loc];
            }

            if(arr2[next]==0){
                // cout << next<<'\n';
                q.push(next);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << arr[i] <<'\n';
    }
}