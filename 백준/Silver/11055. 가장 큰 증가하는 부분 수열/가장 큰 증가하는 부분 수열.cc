#include <bits/stdc++.h>>

using namespace std;

int arr[1010] = {0};
int arr2[1010] = {1};
int MAX = 1;

int GO(int N);

int main() {

  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  arr2[1]=arr[1];
  if(arr2[1]>MAX){
    MAX=arr2[1];
  }
  //cout << arr2[1] << ' ';
  for(int i=2;i<=N;i++){
    arr2[i]=arr[i];
    for(int j=1; j<i; j++){
      if(arr[i] > arr[j]){
        if(arr2[j]+arr[i]>=arr2[i])
          arr2[i]= arr[i] + arr2[j];
      }
    }
    if(arr2[i]>MAX){
      MAX = arr2[i];
    }
  }
  
  cout << MAX;
  
}

