#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a;
  cin >> a;
  int count=a;
  for (int i=1; i<a+1;i++){
    
    for(int j=1;j<a+1;j++){
      if(j == a) cout << "*\n";
      else if(j <= a-i) cout << ' ';
      else if(j > a-i) cout << '*';
    }
    
  }
  return 0;
}