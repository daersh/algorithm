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
  MAX=1;
  arr2[1]=1;
  arr3[1]=1;
  for(int i=2;i<=n;i++){
    arr2[i]=1;
    arr3[i]=1;
    if(arr[i]>=arr[i-1]){
      arr2[i]=arr2[i-1]+1;
    }
    if(arr[i]<=arr[i-1]){
      arr3[i]=arr3[i-1]+1;
    }
    if(MAX<arr2[i]) MAX=arr2[i];
    if(MAX<arr3[i]) MAX=arr3[i];
  }
  
  cout << MAX;
}
