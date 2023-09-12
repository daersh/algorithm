#include <bits/stdc++.h>

using namespace std;
int N,M;

int x;
long long arr[1000100];
long long arr1[1000100];
long long result;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    int i,j;

    for(i=1;i<=N;i++){
        cin >> arr[i];
        arr1[i]=arr1[i-1]+arr[i];
    }

    for(i=M;i<=N; i++){
        if (arr1[i]-arr1[i-M] > result){
            result= arr1[i]-arr1[i-M];
        }

    }
    cout << result;
    return 0;
}