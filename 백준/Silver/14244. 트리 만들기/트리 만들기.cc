#include <iostream>
using namespace std;

int main() {

  int M, N;
  cin >> M >> N;
  int count= 1;
  cout << "0 1\n";
  
  for(int i=1; i<N; i++){
    cout << 1 << ' ' << i+1 << endl;
    count++;
  }
  
  for(int i=count; i< M-1; i++){
    cout << i << ' ' << i+1 << endl;
  }
  
}