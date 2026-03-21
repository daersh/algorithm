#include <bits/stdc++.h>>

using namespace std;

long arr[1000010]={0};

long insert(int n){
  
    if(arr[n]==0){
      arr[n]= (insert(n-1)+insert(n-2)+insert(n-3))%1000000009;
    }
  return arr[n];
}

int main() {
  int t , n;
  cin >> t;
  arr[1]= 1;
  arr[2]= 2;
  arr[3]= 4;
  arr[4]= 7;
  long result;
  for(int i=0; i<t;i++){
    cin >> n;
    
    if(arr[n]==0){
      result = insert(n);
    } else
      result = arr[n];
    
    cout << result << '\n';
  }
  
}


