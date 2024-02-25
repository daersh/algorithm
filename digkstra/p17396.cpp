#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<long long,int> pii;
const long long INF = 1e15;

int arr[100010];
int visited[100010];
long long d[100010];


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m ;
    cin >> n >> m;

    for(int i =0 ;i < n ; i++){
        cin >> arr[i];
    }
    arr[n-1]=0;
    vector<pii> vec[n+1];

    for (int i = 0; i < m; i++)
    {
        int x, y , z;
        cin >> x >> y >> z;

        vec[x].push_back(make_pair(z,y));
        vec[y].push_back(make_pair(z,x));
    }
    fill(&d[1],&d[n+1],INF);
    priority_queue<pii, vector<pii>, greater<pii> > pque;
    pque.push(make_pair(0,0));

    while(!pque.empty()){
        long long dd= pque.top().first;
        int ll= pque.top().second;
        pque.pop();
        // cout << "dd: " << dd <<"  ll: "<<ll<<'\n';
        if(dd>d[ll]) continue;
        
        for (int i = 0; i < vec[ll].size(); i++)
        {
            long long ddd= vec[ll][i].first;
            int lll= vec[ll][i].second;

            if(arr[lll]==1) continue;

            if(ddd+dd<d[lll]){
                d[lll]=ddd+dd;
                pque.push(make_pair(d[lll],lll));
            }
        }
        
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout <<d[i]<<' ';
    // }
    if(d[n-1]==INF) cout <<"-1";
    else 
        cout << d[n-1];
    
}