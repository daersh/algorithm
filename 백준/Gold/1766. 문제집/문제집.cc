#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int > pii;

int main(){
    int n,m;
    cin >> n >> m;
    int arr[n+1];
    vector<int> vec[n+1];
    // queue<int> q;
    priority_queue<int, vector<int>, greater<int> > q;

    for(int i=0;i<=n;i++){
        arr[i]=0;
    }

    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y; 
        vec[x].push_back(y);
        arr[y]++;
    }

    for(int i=1; i<=n; i++){
        if(arr[i]==0) q.push(i);
    }

    vector<int> result;

    while (!q.empty())
    {
        int loc = q.top();
        //cout << "loc: " <<loc <<'\n';
        result.push_back(loc);
        q.pop();
        for(int i=0; i< vec[loc].size(); i++){
            int next=vec[loc][i];
            arr[next]--;
            if(arr[next]==0) q.push(next);
        }
    }

    for(int i=0; i< n ;i++){
        cout << result[i]<<' ';
    }
}