#include <bits/stdc++.h>>

using namespace std;

int main() {

  int n, k;
  cin >> n;
  vector<int> stack;
  
  for(int i =0; i < n; i++){
    cin >> k;
    if(k !=0){
      stack.push_back(k);
    }else {
      stack.pop_back();
    }
  }
  int sum=0;
  while(stack.empty()!=true){
    sum+=stack.back();
    stack.pop_back();
  }
  cout << sum;
}
// 