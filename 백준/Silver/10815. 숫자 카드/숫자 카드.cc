//재귀를 사용한 방식
//P1920
#include <iostream>
#include <algorithm>

using namespace std;

void binary_search(int *arr,int start, int end, int key){
  if(start> end){
    cout << "0 ";
    return;
  }

  int mid = (start+end)/2; 

  if(arr[mid]<key){ //key가 더 클 때
    binary_search(arr,mid+1, end, key);
  }else if(arr[mid]>key){//key가 더 작을 때
    binary_search(arr,start, mid-1, key);    
  }else{
    cout << "1 " ;
    return;
  }
  
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0); //cin 속도 해결
  int arr1[500010];
  int arr2[500010];


  int N;
  cin >>N;
  for(int i=0;i<N;i++){
    cin >> arr1[i];
  }


  int M;
  cin >> M;
  for(int i=0;i<M;i++){
    cin >> arr2[i];
  }


  sort(arr1,arr1+N);// search하기 위해 sort 필요
  
  int start= 0;
  int end = N-1;  


  for(int i =0; i < M; i++){
    binary_search(arr1, start, end, arr2[i]);
    
  }

  return 0;
}