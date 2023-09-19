#include <bits/stdc++.h>

using namespace std;
int arr[210];

int GetP(int x){
    if(arr[x]!=x)   return arr[x]=GetP(arr[x]);
    return x;
}

void Ufind(int x, int y){
    x=GetP(x);
    y=GetP(y);
    if(x>y) arr[x]=y;
    else arr[y]=x;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N,M;
    cin >>N >>M;
    int x,y,z;
    for(int i=1;i<=N;i++)    arr[i]=i;

    for(int i=1;i<=N;i++)   
        for(int j=1;j<=N;j++)
        {
            cin >> x;
            if(x==1) Ufind(i,j);
        }

    for(int i=1;i<=N;i++) GetP(i);
    cin >> y; y= arr[y]; z=false;
    for(int i=2;i<=M;i++){
        cin >> x;
        if(arr[x]!=y || arr[x]==0)   z=true;
        
    }
    if(z==true) cout << "NO";
    else cout << "YES";
    return 0;
}