#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;
typedef pair<int,int> pii;

vector<int> vec[32001];
pair<int,int> arr[32001];

bool compare(pair<int,int>a, pair<int,int> b){
    return a.second<b.second;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        arr[i].first=i;
    }

    for(int i=0; i< m ; i++){
        int x,y;
        cin >> x>>y;
        vec[x].push_back(y);
        
    }

    queue<int> q;

    for(int i=1; i<=n;i++){
        if(arr[i].second==0) {
            q.push(i);
        }
    }
    
    while (!q.empty())
    {
        int loc = q.front();
        q.pop();
        for(int i=0; i< vec[loc].size();i++){
            q.push(vec[loc][i]);
        }
    }

    sort(&arr[1],&arr[n+1],compare);
    for(int i=1; i<=n;i++){
        cout << arr[i].first<<' ';
    }
}