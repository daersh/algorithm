#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t=0;t<T;t++){

        int n;
        cin >> n;
        //입력받은 정수
        int arr[n+1];
        //해당 정수의 위상
        int arr2[n+1];
        int visited[n+1];
        fill(&visited[0],&visited[n+1],0);
        vector<int> vec[n+1];

        for(int i=1; i<=n; i++){
            cin >> arr[i];

        }
        fill(&arr2[0],&arr2[n+1],0);
        int m;
        cin >> m;

        for(int i=0;i<m;i++){
            int x,y;
            cin>> x>>y;
            
            visited[arr[x]]=true;
            visited[arr[y]]=true;
            
            // x가 y 앞이다.
            vec[arr[x]].push_back(arr[y]);
            arr2[arr[y]]++;
        }
        int cnt=1;
        for(int i=1; i<=n;i++){
            cout << visited[i]<<' ';
        }cout <<'\n';
        queue<int> q;
        for (int i = 1; i <=n; i++)
        {
            if(arr2[i]==0&&visited[i]==true){
                q.push(i);
            }
        }
        
        while (!q.empty())
        {
            if(visited[cnt]==false) {
                cout << arr[cnt]<<' ';
                cnt++;
                continue;
            }
            int loc = q.front();
            q.pop();
            cout << arr[loc] << ' ';

            for(int i=0; i<vec[loc].size();i++){
                
                arr2[vec[loc][i]]--;

                if(arr2[vec[loc][i]]==0){
                    q.push(vec[loc][i]);
                }
            }
            cnt++;
        }
        
        for(int i=cnt;i<=n;i++){
            cout <<arr[i]<<' ';
        }
        cout<<'\n';
    }

}
