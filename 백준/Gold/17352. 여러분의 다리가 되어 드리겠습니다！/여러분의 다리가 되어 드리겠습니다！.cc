#include <bits/stdc++.h>

using namespace std;

int arr[400010];

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

    if(x>y) arr[x]=y;
    else arr[y]=x;

}//기본 형태

int main(){
std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        //노드의 부모를 자신으로 설정
        arr[i]=i;
    }
    int x,y;

    
    for(int i=1;i<=N-2;i++){
        cin >> x>>y;
        union_parent(x,y);
    }
    for(int i=1;i<=N;i++){
        find_parent(i);
        //cout << arr[i] <<' ';
    }
    //cout << '\n';

    int start=arr[1];
    for(int i=2;i<=N;i++){
        if(start!=arr[i]){
            cout << start <<' '<< arr[i] ;
            return 0;
        }
    }

}