#include <bits/stdc++.h>

using namespace std;


int main() {
  vector<int> a[30] ;
  int N;

  for(int i=0; i<5 ; i++){
    cin >> N;
    
    if(a[N].size()== 0){

      a[N].push_back(1);

    }else if(a[N][0]==1){

      a[N].pop_back();
      
    }
    
  }
  
  for(int i=0;i<11;i++){
    if(a[i].size()==1){
      cout << i ;
    }
  }
}