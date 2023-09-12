#include <bits/stdc++.h>

using namespace std;
int N,M;

long long result;
int arr[101000];
int arr2[101000];

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;


    for(int i=1;i<=N;i++){
        cin >> arr[i];
        arr2[i]= arr2[i-1]+arr[i];
    }
    cin >> M;
    int x, y;
    for(int i=0;i<M;i++){
        cin >> x >> y;

        cout << arr2[y]-arr2[x-1] <<'\n';
    }
    return 0;
}