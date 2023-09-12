#include <bits/stdc++.h>

using namespace std;

long long N, M;

struct data{
  long long val;
  string ascii;
  //1: *
  //2: +
  //3: -
  //4: /
}insert;

vector<struct data> vec;
vector<int> visited;

queue<struct data> q;
int minus_use;
int nanugi_use;
void bfs(){
  
  while(!q.empty()){
    long long x= q.front().val;
    string y= q.front().ascii;
    q.pop();
    for(int i=0;i<visited.size();i++){
      if(x==visited[i]) continue;
    }

    visited.push_back(x);
    //cout << x << ' ' << y <<'\n';

    if(x==M){
      if(!y.empty())
        cout << y;
      else{
        cout << 0;
      }
      return;
    }
    if(x!=0 ){
      if(x*x <= M*5 && x!=1 ){
        insert.val=x*x;
        insert.ascii= y;
        insert.ascii.push_back('*');
        q.push(insert);
      }
      if(x+x <= M+M ){
        insert.val=x+x;
        insert.ascii= y;
        insert.ascii.push_back('+');
        q.push(insert);
      }
    }
    if(nanugi_use==0 && x != 1){
      nanugi_use=1;
      insert.val=x/x;
      insert.ascii= y;
      insert.ascii.push_back('/');
      q.push(insert);
    }
  }

  cout << -1;
  
}

int main(){
  struct  data insert;
  

  cin >> N >> M;
  insert.val= N;

  q.push(insert);
  struct data cmp;

  bfs();  

}
