#include <bits/stdc++.h>

using namespace std;
int N,M;

long long arr[101000];
long long arr2[101000];
long long sum;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    int i,x;

    for(i=1;i<=N;i++){
        cin >>arr[i];
        arr2[i]=arr2[i-1]+arr[i];
    }
    

    for(i=1;i<=N;i++){
        sum+=(arr2[N]-arr2[i])*arr[i];
    }
    cout << sum;

}