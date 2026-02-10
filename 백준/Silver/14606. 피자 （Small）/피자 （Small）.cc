#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    queue<int> q;
    q.push(n);
    int result = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v==1) continue;
        int vv = v/2;
        int vvv = v%2==1? v/2+1 : v/2;
        result += vv*vvv;
        q.push(vv);
        q.push(vvv);
    }
    cout << result;
}