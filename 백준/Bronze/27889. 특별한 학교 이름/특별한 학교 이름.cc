#include <bits/stdc++.h>>

using namespace std;

int arr[500][130000] = {0};
int arr2[130000] = {1};
int MAX = 0;

int GO(int N, int M);

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string n;
  cin >> n;
  if (n == "NLCS")
    cout << "North London Collegiate School";
  if (n == "BHA")
    cout << "Branksome Hall Asia";
  if (n == "KIS")
    cout << "Korea International School";
  if (n == "SJA")
    cout << "St. Johnsbury Academy";
}
// n*(n+1)/2
