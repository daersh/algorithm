#include <bits/stdc++.h>>

using namespace std;

int arr[100010] = {0};

int main() {
  int N;

  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 3;

  arr[4] = 1;
  arr[5] = 2;
  arr[6] = 3;
  cin >> N;

  for (int i = 7; i <= N; i++) {
    int val = (int)sqrt(i);
    int min = 10000;

    for (int j = val; j > 0; j--) {
      if (1 + arr[i - j * j] < min)
        min = 1 + arr[i - j * j];
    }
    arr[i]=min;
  }
  cout << arr[N];
}
