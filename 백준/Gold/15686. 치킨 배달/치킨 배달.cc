#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int dist_list[10000][10000];
vector<pii> home, chicken;
int n, m;
int result = 1e9;

// 사이 거리 구하기
int dist(pii a, pii b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int calculate_dist(vector<int> active_chickent_list) {
  int sum = 0;
  for (int i = 0; i < home.size(); i++) {
    int min_dist = 1e9;
    for (int j = 0; j < active_chickent_list.size(); j++) {
      int d = dist_list[i][active_chickent_list[j]];
      if (d < min_dist)
        min_dist = d;
    }
    sum += min_dist;
  }
  return sum;
}

// dfs
void dfs(int c, vector<int> active_chickent_list) {
  pii chicken_pos = chicken[c];

  if (c > chicken.size())
    return;
  if (active_chickent_list.size() == m) {
    int sum = calculate_dist(active_chickent_list);
    // cout << "sum: " << sum << '\n';
    // cout << "result: " << result << '\n';
    if (sum < result)
      result = sum;
  }

  // 1. 현재 치킨집을 선택하지 않는 경우
  dfs(c + 1, active_chickent_list);
  // 2. 현재 치킨집을 선택하는 경우
  active_chickent_list.push_back(c);
  dfs(c + 1, active_chickent_list);
  active_chickent_list.pop_back();
}

int main() {
  cin >> n >> m;

  int v;
  // 0: 빈 집, 1: 집, 2: 치킨집
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> v;
      if (v == 1)
        home.push_back({i, j});
      else if (v == 2)
        chicken.push_back({i, j});
    }
  // 집과 치킨집의 거리 구하기

  for (int i = 0; i < home.size(); i++) {
    for (int j = 0; j < chicken.size(); j++) {
      dist_list[i][j] = dist(home[i], chicken[j]);
    }
  }

  // 치킨번호
  dfs(0, vector<int>());
  cout << result << endl;
    return 0;
}
