#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;
const int INF = 1e9;
vector<pii> vec[1001];

int d[1001];


/*
    합리적인 이동경로란 이동할 때 목적지에 가까워지면서 이동하는 경우를 의미
    멀어지는 경우가 뭘까
    
*/


int main(){
    int n, m;
    cin >> n >> m;
    fill(&d[0],&d[n+1],INF);
    for(int i=0;i<m;i++){
        int x, y,z;
        cin >> x >>y>>z;
        vec[x].push_back(make_pair(z,y));
        vec[y].push_back(make_pair(z,x));
    }

    priority_queue<pii,vector<pii>, greater<pii> > pque;
    
    pque.push(make_pair(0,1));
    int cnt=0;
    while (!pque.empty())
    {
        int dd= pque.top().first;
        int ll= pque.top().second;
        pque.pop();
        if(dd>d[ll]) continue;
        
        for(int i=0; i< vec[ll].size(); i++){
            int ddd= vec[ll][i].first;
            int lll= vec[ll][i].second;
            
            if(ddd+dd<=d[lll]){
                if(lll==2 && ddd+dd<=d[2]){
                    if(ddd+dd==d[2]){
                        cnt++;
                    }else{
                        cnt=1;
                    }
                }
                d[lll]=ddd+dd;
                pque.push(make_pair(d[lll],lll));
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout << d[i]<<'\n';
    }
    cout << cnt;
}