#include <bits/stdc++.h>

using namespace std;
int arr[1000010];
int find_parent(int x){
    if(arr[x]!=x){
//**********!!!중요!!!접근 한 배열의 부모 경로 압축시킴*********** 
        return arr[x] = find_parent(arr[x]);
    }else{
        return x; 
    }
}
void union_parent(int x, int y){
    x=find_parent(x);
    y=find_parent(y);
    if(x>y) arr[x]=y;
    else arr[y]=x;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N,M;
    cin >> N >>M;
    
    for(int i=1;i<=N;i++){
        arr[i]=i;
    }
    int x,y,z;
    for(int i=1;i<=M;i++){
        cin >> z;
        cin >> x>>y;
        if(z==0){
        union_parent(x,y);
        }
        else if(z==1){
            if( find_parent(x)==find_parent(y)){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
}