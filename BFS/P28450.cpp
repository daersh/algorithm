#include <iostream>
#include <queue>


using namespace std;

struct Loc{
  int x;
  int y;
  int noon;

}loc;
int visited[1000][1000];

int main(){    
  ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
  int n,m,k;
  cin >> n >> m;
  int arr[n][m];

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin >> arr[i][j];
    }
  }

  cin >> k;
  int kk=k-arr[0][0];
  if(kk<0){
    cout << "NO";
    return 0;
  }
  struct compare{
    bool operator()(Loc a, Loc b){
      if(a.noon>b.noon){
        return true;
      }else 
        return false;
    }
  };

  priority_queue<Loc, vector<Loc> ,compare > q;
  loc.x=0;
  loc.y=0;
  loc.noon=kk;
  q.push(loc);
  int min = 1e9;
  Loc a;

  while(!q.empty()){
    a = q.top();
    q.pop();
    Loc b;
    if(a.x==n-1 && a.y==m-1){
        min = k-a.noon;
      break;
    }

    if(a.x+1<n && arr[a.x+1][a.y]<=a.noon){
      b.x = a.x+1;
      b.y = a.y;
      b.noon = a.noon-arr[a.x+1][a.y];
      if(visited[b.x][b.y]==0 || visited[b.x][b.y] < b.noon ){
        q.push(b);
        visited[b.x][b.y] = b.noon;
      }
    }

    if(a.y+1<m && arr[a.x][a.y+1]<=a.noon){
      b.x=a.x;
      b.y=a.y+1;
      b.noon = a.noon-arr[a.x][a.y+1];
      if(visited[b.x][b.y]==0 || visited[b.x][b.y] < b.noon ){
        q.push(b);
        visited[b.x][b.y] = b.noon;
      }

    }
  }

  if(min==1e9)
    cout << "NO";
  else{
    cout << "YES\n";
    cout << min;
  }  
}

