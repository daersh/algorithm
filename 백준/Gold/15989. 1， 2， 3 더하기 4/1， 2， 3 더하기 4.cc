#include <bits/stdc++.h>>

using namespace std;

int arr[10010] = {0};
int arr2[1010] = {1};
int MAX = 0;

int GO(int N, int M);

int main() {
  int N;
  cin >> N;
  arr[1]=1;
  arr[2]=2;
  arr[3]=3;
  arr[4]=4;
  arr[5]=5;
  arr[6]=7;
  arr[7]=8;
  arr[8]=10;
  int a=4;
  int b=4;
  int c=5;
  
  for(int i=9;i<10010;){
    
    arr[i]=arr[i-3]+1+a; i++;
    arr[i]=arr[i-3]+2+b; i++;
    arr[i]=arr[i-3]+1+c; i++;
    a+=1;
    b+=2;
    c+=1;
    arr[i]=arr[i-3]+2+a; i++;
    arr[i]=arr[i-3]+1+b; i++;
    arr[i]=arr[i-3]+2+c; i++;
    a+=2;
    b+=1;
    c+=2;
  }
  
  for(int i=0;i<N;i++){
    int M;
    cin >> M;
    cout << arr[M] << '\n';
  }
  
  
  
}

// 333 : 
// 3333
// 3331
// 33331
// 3332
