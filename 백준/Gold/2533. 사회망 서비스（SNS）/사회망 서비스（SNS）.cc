#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> vec[1000010];
int ali[1000010][2];
int visited[1000010];

void dp(int loc){
    visited[loc]++;
    ali[loc][0]=1;

    for (int i = 0; i < vec[loc].size(); i++)
    {
        int next = vec[loc][i];
        if(visited[next])continue;

        dp(next);
        ali[loc][1]+=ali[next][0];
        ali[loc][0]+=min(ali[next][1],ali[next][0]);
    }
}

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    dp(1);
    cout << min(ali[1][0],ali[1][1]);

}

