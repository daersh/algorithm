#include <bits/stdc++.h>

using namespace std;

int T,N;

int main() {
  cin >> T;
  int i;
  for(i=0;i<T;i++){
    cin >> N;
    int arr[N+1];
    int tf = false;
    for (int j=0; j<N;j++){
      cin >> arr[j];

    }

    int front=0, back= 0;
   
    front= arr[0];
    back = arr[N-1];

    if(arr[0]>0 && arr[N-1]>0){
        cout << "YES"<<'\n';
        tf = true;
    }
    else if(arr[0]>0 && arr[1]>0) {
        cout << "YES" << '\n';\
        tf = true;
    }else if(arr[N-1]>0 &&arr[N-2] >0){
        tf= true;
        cout << "YES" << '\n';
    }

    for(int j=1;j<N;j++){
      if(tf= true) break;
      front+= arr[j];
      back += arr[N-1-j];
      if(front>0 && back>0){
        cout << "YES" << '\n';
        break;
        tf=true;
      }else if(front>0 && back>0){
        
      }

    }

  }  

}


// 3 -2 -5 6 -100  