#include <bits/stdc++.h>

using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

void ori() {
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    cout << cur << ' ';
    if (lc[cur])
      q.push(lc [cur] );
    if (rc[cur])
      q.push(rc [cur] );
  }
}

int n;
vector<int> vec[100001]; //vec 10만개생성
int tree[1000001];

void dfs(int num){
  //if(tree[num]) return;
  //tree[num] = true;
  for(int i : vec[num]){
    if(tree[num]==i) continue;
    tree[i]=num;
    dfs(i);
  }
}

int main(){
  int N;
  cin >> N;
  int x,y;
  for(int i=0;i<N-1;i++){
    cin >> x >> y;
    vec[x].push_back(y);
    vec[y].push_back(x);
  }
  dfs(1);
  for(int i=2;i<=N;i++)
    cout << tree[i] << '\n';
  return 0;
}