#include <bits/stdc++.h>>

using namespace std;

int arr[100010] = {0};
int arr2[130000] = {0};
int MAX = -11111110;

int GO(int N);

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  for(int i=1; i <=N; i++){
    cin >> arr[i];
  }
  arr2[1]=arr[1];
  if(MAX<arr2[1]) MAX=arr2[1];

  for(int i=2; i <=N; i++){
    arr2[i]=arr[i];
    if(arr2[i]<arr2[i]+arr2[i-1]){
      arr2[i]+=arr2[i-1];
    }
    
    //cout<<arr2[i]<<endl;
    if(MAX<arr2[i]) MAX=arr2[i];

  }
  cout << MAX;
}
