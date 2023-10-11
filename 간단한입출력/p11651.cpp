#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;
#include <vector>

typedef pair<int, int> pii;

bool cmp(pii p1, pii p2){
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int N;
    cin >>N;
    int x,y;
    vector<pair<int,int> > vec;
    // priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pque;
    for(int i=0;i<N;i++){
        cin >> x >>y;
        // pque.push(make_pair(y,x));
        vec.push_back(make_pair(x,y));
    }
    sort(vec.begin(),vec.end(),cmp);
    cout << '\n';
    cout << "*****vec*******\n";

    for(int i=0;i<N;i++){
        cout << vec[i].first << ' '<< vec[i].second<< '\n';
    }
    // for(int i=0;i<N;i++){
    //     cout << pque.top().second << ' '<< pque.top().first<< '\n';
    //     pque.pop();
    // }
}