#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;
int N,M;
vector<pii> vec[50010];
int d[50010];
const int INF
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> N >> M;
    int x, y, z;
    for(int i=0;i<M;i++){
        cin >> x>>y>>z;
        vec[x].push_back(make_pair(z,y));
        vec[y].push_back(make_pair(z,x));
    }

    

}