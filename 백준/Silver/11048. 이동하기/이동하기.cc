#include <bits/stdc++.h>>

using namespace std;

int arr[1010] = {0};
int arr2[1010] = {1};
int MAX = 0;

int arr1[1010][1010]= {0};
int arr3[1010][1010]= {0};
int GO(int N, int M);

int main() {
  int N,M;
  cin >> N >> M;
  for(int i=1;i<= N;i++){
    for(int j=1;j<=M; j++){
      cin >> arr1[i][j];
    }
  }
  
  arr3[1][1]=arr1[1][1];
  //cout << GO(N,M)<< endl;
  for(int i=1;i<= N;i++){
    for(int j=1;j<=M; j++){
      //2 1
      if(arr3[i][j]+arr1[i+1][j]>arr3[i+1][j])
        arr3[i+1][j]=arr3[i][j]+arr1[i+1][j];
      if(arr3[i][j]+arr1[i][j+1]>arr3[i][j+1])
        arr3[i][j+1]=arr3[i][j]+arr1[i][j+1];
      if(arr3[i][j]+arr1[i+1][j+1]>arr3[i+1][j+1])
        arr3[i+1][j+1] = arr3[i][j]+arr1[i+1][j+1];
    }
   
  }
  /*
for(int i=1;i<= N;i++){
    for(int j=1;j<=M; j++){
      cout << arr3[i][j] <<' ';
    }
  cout <<endl;
  }
  */
  cout << arr3[N][M];
}

