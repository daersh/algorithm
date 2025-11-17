#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n , m;
    cin >> n >> m;

    queue<int> q;
    queue<int> res;
    for(int i=1; i<=n; i++) q.push(i);
    int cnt=0;
    while(q.size() > 0){
        
        if(cnt++==m-1)  {
            res.push(q.front());
            cnt=0;
        }
        else 
            q.push(q.front());
        q.pop();
    }

    cout << "<";
    while(!res.empty()){
        cout << res.front();
        res.pop();
        if(!res.empty()) 
            cout << ", ";
    }
    cout << ">" << "\n";

    return 0;
}