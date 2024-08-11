#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

int n, m ;
priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int a;
    for(int i=0;i<n;i++){
        cin >> a;
        pq.push(a);
    }

    while(!pq.empty()){
        
        a= pq.top();
        pq.pop();
        if(m>=a)
            m++;
        else{
            cout << m;
            return 0;
        }
    }
    cout << m;
}