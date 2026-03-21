#include <bits/stdc++.h>>

using namespace std;

int arr[100010] = {0};
int arr2[130000] = {0};
double MAX = -11111110;

int GO(int N);

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  double a[10010] = {0};
  double b[10010] = {0};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  b[0] = a[0];
  if (MAX < b[0])
    MAX = b[0];

  for (int i = 1; i < n; i++) {
    if (a[i] == 0)
      continue;
    b[i] = a[i];
    if (b[i] < a[i] * b[i - 1]) {
      b[i] = a[i] * b[i - 1];
    }
    if (MAX < b[i])
      MAX = b[i];
  }
  printf("%.3lf", MAX);
}
