#include <bits/stdc++.h>

using namespace std;
int N,M,L;

int arr[1000010];
int arr2[1000010];

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> N >> M;
    int i;
    for(i=1;i<=N;i++){
        cin >> arr[i];

    }

    int x ,y, z;

    for(i=1;i<=M;i++){
        cin >> x >> y >> z;
        arr2[x]+=z;
        arr2[y+1]+=-z;
    }
    
    for(i=1;i<=N;i++){
        arr2[i]+=arr2[i-1];
       // cout << arr2[i] << ' ';
    }
    for(i=1;i<=N;i++){
        arr[i]+=arr2[i];
        cout << arr[i] << " ";
    }

}