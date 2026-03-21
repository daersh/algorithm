#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
const int INF = 1e9;

int N, M, sp, dest1, dest2;
vector<pii> vec[200010];
int d1[200010];
int d2[200010];

void digkstra(int start) {
  priority_queue<pii, vector<pii>, greater<pii>> pque;
  d1[start] = 0;
  pque.push(make_pair(0, start));
  while (!pque.empty()) {
    int dd = pque.top().first;
    int ll = pque.top().second;
    pque.pop();
    if (dd > d1[ll]) {
      continue;
    }

    for (int i = 0; i < vec[ll].size(); i++) {
      int ddd = vec[ll][i].first;
      int lll = vec[ll][i].second;
      if (ddd + dd < d1[lll]) {
        d1[lll] = ddd + dd;
        pque.push(make_pair(d1[lll], lll));
      }
    }
  }
}

int main() {
  cin >> M >> N >> sp >> dest1 >> dest2;
  int x, y, z;
  for (int i = 0; i < M; i++) {
    cin >> x >> y >> z;
    vec[x].push_back(make_pair(z, y));
    vec[y].push_back(make_pair(z, x));
  }
  fill(&d1[0], &d1[N + 10], INF);
  digkstra(sp);
  int stod1 = d1[dest1];

  int stod2 = d1[dest2];


  fill(&d1[0], &d1[N + 10], INF);
  
  digkstra(dest1);
  
  int d1tod2 = d1[dest2];



  if (stod1 > stod2) {
    cout << stod2 + d1tod2;
  } else {
    cout << stod1 + d1tod2;
  }
}