#include <iostream>
#include<set>
#include<queue>
#include<vector>

using namespace std;


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    set<string> names;
    priority_queue<string, vector<string>,greater<string> >q;
    int n, m, cnt=0;
    cin >> n >> m;
    for(int i=0; i< n ;i++){
        string x;
        cin >> x;
        names.insert(x);
    }

    for(int i=0; i< m ;i++){
        string x;
        cin >>x;
        if(names.find(x)!=names.end()){
            cnt++;
            q.push(x);
        }
    }
    cout << cnt<<'\n';
    while (!q.empty())
    {
        cout << q.top() <<'\n';
        q.pop();
    }
}