#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;
const int INF =1e9;
typedef pair<int,int> pii;

bool compare(pii x, pii y){
    if(x==y) return x.second<y.second;
    return x.first < y.first;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >>n;
    pii arr[n+1];
    priority_queue<pii, vector<pii>, greater<pii> >  pq;
    for(int i=0; i< n ;i++){
        int x, y;
        cin >> x >> y;
        pq.push(make_pair(x,y));
    }

    int cnt=0;
    vector<int> vec;
    vec.push_back(pq.top().second);
    int min=vec[0];
    pq.pop();
    
    while (!pq.empty())
    {
        bool tf=false;
        
        for(int i=0; i<vec.size(); i++){
            if(vec[i]<=pq.top().first){
                vec[i]=pq.top().second;
                pq.pop();
                tf=true;
                break;
            }
        }
        if(tf!=true){
            vec.push_back(pq.top().second);
            pq.pop();
        }
    }
    
    cout <<vec.size();
}
