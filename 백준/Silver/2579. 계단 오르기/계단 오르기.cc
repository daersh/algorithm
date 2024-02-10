#include <bits/stdc++.h>>

using namespace std;

int arr[310] = {0};
int arr2[310] = {0};

int GO(int N);

int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  arr2[1] = arr[1];
  arr2[2] = arr[1] + arr[2];

  cout << GO(N);
}

int GO(int N) {
  if (arr2[N] == 0) {
    if (N >= 3) {
      if (GO(N - 3) + arr[N - 1] + arr[N] > GO(N - 2) + arr[N]) {
        arr2[N] = GO(N - 3) + arr[N - 1] + arr[N];
      } else {
        arr2[N] = GO(N - 2) + arr[N];
      }
    }
  }
  return arr2[N];
}
