#include <iostream>

using namespace std;
int INF= 1e9;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    int arr[n+1];
    arr[0]=0;
    for(int i=1;i<=n;i++){
        cin >>arr[i];
        arr[i]=arr[i-1]+arr[i];
    }
    int max=-INF;
    int x;
    for(int i=m;i<=n;i++){
        x=arr[i]-arr[i-m];
        if(max<x){
            max=x;
        }
    }
    cout << max;
}