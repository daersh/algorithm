#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
using pii= pair<int,int>;
struct compare{
    bool operator()(int a, int b){
        return a > b;
    }
};

bool comp(pii a, pii b){
    if(a.second==b.second){
        return a.first < b.first;
    }
    return a.second< b.second;
}

using pque = priority_queue<int, vector<int>, compare >;



int main(){
    int n;
    cin >> n;
    int a,b;
    vector<pii> arr;
    for (int i = 0; i < n; i++){
        cin >> a>> b;
        if(a>b){
            arr.push_back({b,a});
        }
        else{
            arr.push_back({a,b});
        }
    }

    sort(arr.begin(),arr.end(), comp);
    int len;
    cin >> len;
    pque q;
    int res=0;
    for(pii loc: arr){
        if(loc.second-loc.first>len) continue;
        // cout << "loc: " << loc.first <<'_'<<loc.second<<'\n';
        q.push(loc.first);
        while(!q.empty()){
            int p = q.top();
            // cout << "p: " << p <<'\n';
            if(loc.second - p <= len ) 
                break;
            q.pop();
        }
        int size =q.size();
        // cout<< "        " << q.size()<<'\n';
        res= max(res, size );
    }
    cout << res;
}