#include <bits/stdc++.h>

using namespace std;


int main() {

  int N , M, Q;
  cin >> N >> M >>Q;
  int arr[N+2][M+2] ;
  memset(arr,0,sizeof(arr));

  int i,j;
  int x,r,v;
  int arr1[N+2];
  int arr2[M+2];
  memset(arr1,0,sizeof(arr));
  memset(arr2,0,sizeof(arr));

  for(i=0;i<Q;i++){
    cin >> x >> r >>v;

    //행 (가로)
    if(x==1){
      arr1[r]+=v;    
    }
    //열(세로)
    else if(x==2){
      arr2[r]+=v;
    }
  }


  for(i=1;i<=N;i++){
    for(j=1;j<=M;j++){
      cout << arr1[i]+ arr2[j]<<' ';
    }
    cout <<'\n';
  }

}