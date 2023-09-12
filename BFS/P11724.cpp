#include <bits/stdc++.h>

using namespace std;


int c[1100];
int arr[1100];
int N, M, V;
int count1=0;

void dfs(int x, vector<int> vec[]) {

  int i,next;
  if(c[x]== true) return ;
  
  c[x]=true;

  for(i=0; i< vec[x].size();i++ ){
    next= vec[x][i];
    dfs(next,vec);
  }
}


int main() {
  cin >> N;
  cin >> M;
  int i,x,y;

  vector<int> vec[N+1];
  for(i=0;i<M;i++){
    cin >> x >> y;
    vec[x].push_back(y);
    vec[y].push_back(x);
  }
  for(i=1; i<N+1;i++){
    if(c[i] == false){
      dfs(i,vec);
      count1 ++;
    }
  }

  printf("%d",count1);

}