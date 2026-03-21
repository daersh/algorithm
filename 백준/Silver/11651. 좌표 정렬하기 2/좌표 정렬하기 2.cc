#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;
#include <vector>

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int N;
    cin >>N;
    int x,y;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pque;

    for(int i=0;i<N;i++){
        cin >> x >>y;
        pque.push(make_pair(y,x));
    }
    
    for(int i=0;i<N;i++){
        cout << pque.top().second << ' '<< pque.top().first<< '\n';
        pque.pop();
    }
    
}