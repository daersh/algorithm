#include <bits/stdc++.h>>

using namespace std;

int arr[1010] = {0};
int arr2[1010] = {1};
int MAX = 1;

int GO(int N);

int main() {
  int N;
  cin >> N;
  for(int i=1;i<=N;i++){
    cin >> arr[i];
  }
  
  int count=0;
  int i=1;
  while(i<N){
    int max=0;
    int loc;
    for(int j=i+1;j<=i+arr[i];j++){
      if(j>=N){
        count+=1;
        goto point;
      }
      if(arr[j]>=max){
        max=arr[j];
        loc=j;
      }
      if(j+arr[j]>loc+max){
        max=arr[j];
        loc=j;
      }
    }
    
    if(max==0){
      count=-1;
      goto point;
    }else{
      count+=1;
      i=loc;
    }
    //cout << i<<"로 이동 \n";
  }

  point:
    cout << count;
}

