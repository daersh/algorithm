#include <bits/stdc++.h>

using namespace std;

long long N, M;


struct data{
    long long val;
    long long count;
}dada;

queue<struct data> q;
int correct=false;

void bfs(){
    while(!q.empty()){
        long long x = q.front().val;
        long long y = q.front().count;
        //cout << x << ' ';
        if(x==M){
            cout  <<y; 
            correct=true;
            return;
        }
        q.pop();
        if(x*2<=M){
            dada.val=x*2;
            dada.count=y+1;
            q.push(dada);
        }
        if((x*10)+1<=M){
            dada.val=(x*10)+1;
            dada.count=y+1;
            q.push(dada);
        }
    }

}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

   cin >> N >> M ;
    dada.val=N;
    dada.count=1;
    q.push(dada);
    
    bfs();

    if(correct==false){
        cout << -1;
    }
    return 0;
}