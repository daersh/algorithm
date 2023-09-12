#include <bits/stdc++.h>

using namespace std;


int main() {
  int N, M;

  cin >> N;
  string arr[N+1];
  string a;

  char x= '?', y ='?';

  for(int i=0; i<N; i++){
    
    cin >> arr[i];
  }
  for(int i=0;i<N;i++){
    if(arr[i]=="?" && i==0){
      y= arr[i+1][0];
      x= '?';
    }else if(arr[i]=="?" && i==N-1){
      x= arr[i-1].back();
      y= '?';
    }else if(arr[i]=="?"){
      x= arr[i-1].back();
      y= arr[i+1][0];
    }
  }


  cin >> M;
  string arr2[M+1];
  for(int i=0;i<M;i++){
    cin >> arr2[i];
    for(int j=0; j<N;j++){
      if(arr2[i] == arr[j]){
        arr2[i] = ".";
        break;
      }
    }
  }

  if(N==1){
    cout << arr2[0];
  }else{
  if( x== '?' ){
    for(int i=0; i<M;i++ ){
      if(y== arr2[i].back()){
        cout << arr2[i];
        break;
      }
    }
  }else if(y=='?'){
    for(int i=0; i<M;i++ ){
      if(x== arr2[i][0]){
        cout << arr2[i];
        break;
      }
    }
  }else{
    for(int i=0; i<M;i++ ){
      if(y==arr2[i].back() && x== arr2[i][0]){
        cout << arr2[i];
        break;
      }
    }
  }
  }
}