#include <bits/stdc++.h>

using namespace std;

int arr[1000010];

int find_parent(int x){
    
    if(arr[x]!=x){
        return find_parent(arr[x]);
    }else{
        return x;
    }

}

void union_parent(int x, int y){
    x=find_parent(x);
    y=find_parent(y);

    if(x>y) arr[x]=y;
    else arr[y]=x;

}//기본 형태

int main(){
    int N,M;
    cin >> N >>M;
    for(int i=1;i<=N;i++){
        //노드의 부모를 자신으로 설정
        arr[i]=i;
    }
    int x,y;

    
    for(int i=1;i<=M;i++){
        cin >> x>>y;
        union_parent(x,y);
    }
    for(int i=1;i<=N;i++){
        cout << arr[i] << ' ';
    }
    cout <<"3의 루트: " << find_parent(3);

}