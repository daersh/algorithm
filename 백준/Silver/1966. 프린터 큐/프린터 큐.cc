#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

typedef pair<int,int> pii;

struct cmp {
    bool operator()(pii a, pii b){
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};

int main (){
    int T;
    cin >> T;
    
    for(int t=0; t<T; t++){
        int n,m;
        queue<pii> q;
        cin >> n >> m;
        priority_queue<pii, vector<pii>, cmp > pq;
        int arr[10]={0};

        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            arr[x]++;
            q.push({i, x});
        }
        
        for(int i=0; i<10; i++){
            if(arr[i]==0) continue;
            pq.push({i, arr[i]});
        }
        
        int cnt =0;

        while(true ){
            pii x = q.front();
            q.pop();
            // cout << x.first << ' ' << x.second << "\n";
            // cout << pq.top().first << ' ' << pq.top().second << "\n";
            if(x.second < pq.top().first ){
                // cout << "repush\n";
                q.push( {x.first, x.second});
            }
            else {
                // cout << "pop\n";
                cnt++;
                pii temp = pq.top();
                pq.pop();
                temp.second--;
                if(temp.second!=0)
                    pq.push(temp);
                if(x.first == m){
                    break;
                }
            }
        }
        cout << cnt << "\n";
    }

}