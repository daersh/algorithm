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

    for(int i=1; i<=n;i++){
        int x,y;
        cin >> x;
        cin >> y;
        arr[i]=x;
        if(y!=-1)
        {
            vec[y].push_back(i);
            arr2[i]++;
            cin >> y;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(arr2[i]==0) q.push(i);
    }
    while (!q.empty())
    {
        
    }
    
}