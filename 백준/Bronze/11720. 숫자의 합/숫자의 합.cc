#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int sum=0;
  string a;
  cin >> a;
  for(int i=0; i<n;i++){
    sum+=(int)a[i]-48;
  }
  cout << sum;
  return 0;
}