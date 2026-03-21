#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>

using namespace std;
int n, k;
int arr[100010];
vector<int> vec;
const int INF = 1e9;

void dp(int loc, int cnt){

  if(arr[loc] > cnt){
    arr[loc] = cnt;
    for(int i=0; i<vec.size(); i++){
      if(loc+vec[i]<=k){
        dp(loc+vec[i], cnt+1);
      }
    }
  }
  
}

int main(){
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    vec.push_back(x);
  }
  
  fill(&arr[0], &arr[100010], INF);

  dp(0,0);
  int res = (arr[k]==INF)?-1 : arr[k];
  cout << res;

  return 0;
}