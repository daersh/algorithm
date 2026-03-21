#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int star = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - star / 2 - 1; j++)
      cout << ' ';
    for (int j = 0; j < star; j++)
      cout << '*';
    cout << '\n';
    star += 2;
  }

  star -= 4;
  while (star >= 1) {
    for (int j = 0; j < n - star / 2 - 1; j++)
      cout << ' ';
    for (int i = 0; i < star; i++)
      cout << '*';
    cout << '\n';
    star -= 2;
  }
}