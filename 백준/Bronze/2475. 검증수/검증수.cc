#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a;
  int sum=0;
  
  for(int i=0;i<5;i++){
    cin >> a;
    sum+=a*a;
  }
  cout << sum%10;
  return 0;
}