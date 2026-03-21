#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {

  int n;
  cin >> n;

  queue<int> q;

  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    if (str == "push") {
      int x;
      cin >> x;
      q.push(x);
    } else if (str == "pop") {
      if (q.empty())
        cout << -1 << endl;
      else {
        cout << q.front() << endl;
        q.pop();
      }
    } else if (str == "size") {
      cout << q.size() << endl;
    } else if (str == "empty") {
      cout << q.empty() << endl;
    } else if (str == "front") {
      if (q.empty())
        cout << -1 << endl;
      else
        cout << q.front() << endl;
    } else if (str == "back") {
      if (q.empty())
        cout << -1 << endl;
      else
        cout << q.back() << endl;
    }
  }
}