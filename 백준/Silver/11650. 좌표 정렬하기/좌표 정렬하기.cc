#include <bits/stdc++.h>>

using namespace std;

int main() {
  int N;
  cin >> N;
  priority_queue<pair<int,int>> q;
      
  for(int i =0; i< N; i++){
    int a, b;
    cin >> a>> b;
    q.push({-a,-b});
  }
  
  for(int i =0; i< N; i++){
    cout << -q.top().first << ' '<< -q.top().second << '\n';
    q.pop();
  }
}