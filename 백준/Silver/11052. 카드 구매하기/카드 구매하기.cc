#include <bits/stdc++.h>>

using namespace std;

int arr[100010] = {0};
int arr2[130000] = {0};
int arr3[130000] = {0};

double MAX = -11111110;

int GO(int N);

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> arr[i];
  }
  
  MAX= arr[1]*n;
  arr2[1]=arr[1]*n;
  
  for(int i=2;i<=n;i++){
    for(int j=i-1;j>0;j--){
      if(i-j > 0){
        if(arr[i]<arr[j]+arr[i-j]){
          arr[i]=arr[j]+arr[i-j];
        }  
      }
    }
  }
  cout << arr[n];
}
