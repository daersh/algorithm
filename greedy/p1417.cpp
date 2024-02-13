#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int,int> pii;

int main(){
    int n ;
    cin >> n ;
    priority_queue<pii,vector<pii> > pque;
    int x;
    cin >> x;
    int s= x;
    int cnt=0;
    for(int i=2; i<=n ; i++){
        cin >> x;
        pque.push(make_pair(x,i));
    }
    while(!pque.empty())
    {
        int v = pque.top().first;
        int l = pque.top().second;
        pque.pop();
        if(v>=s){
            // cout <<v <<'\n';
            cnt++;
            s++;
            v--;
            pque.push(make_pair(v,l));
        }
    }
    cout << cnt;
}