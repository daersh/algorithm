#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

queue<pii> q;
queue<int> q2;
int arr[110];
int arr2[110];

int find_parent(int x){
    
    if(arr[x]!=x){
        return arr[x]= find_parent(arr[x]);
    }else{
        return x;
    }

}

void union_parent(int x, int y){
    x=find_parent(x);
    y=find_parent(y);
    if(arr2[x]<arr2[y]) arr[x]=y;
    else arr[y]=x;
}


int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    int N,M;
    cin >> N >> M;

    for(int i=1;i<=N;i++){
        //노드의 부모를 자신으로 설정
        arr[i]=i;
    }

    int x,y;
    
    for(int i=1;i<=M;i++){
        cin >> x>>y;
        arr2[x]++;
        arr2[y]++;
        q.push(make_pair(x,y));
    }

    // for(int i=1;i<=N;i++){

    //     cout << arr2[i] <<' ';
    // }
    // cout << '\n';
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        union_parent(x,y);
    }

    
    for(int i=1;i<=N;i++){
        //find_parent(i);
        //cout << arr[i] <<' ';
    }
    //cout << '\n';

    int cnt=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==arr[j]){
                cnt++;
                q2.push(i);
                break;
            }
        }
    }

    cout << cnt << '\n' ;
    while (!q2.empty())
    {
        cout << q2.front()<<'\n';
        q2.pop();
    }
    

}
