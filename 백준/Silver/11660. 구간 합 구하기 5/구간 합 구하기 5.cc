#include <bits/stdc++.h>

using namespace std;
int N,M;

int x;
int arr2[1100][1100];
int insert1,insert2,insert3,insert4;
int result;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    int i,j;
    for( i=1;i<=N;i++){
        
        for( j=1;j<=N;j++){
            cin >> x;
            arr2[i][j]=x+arr2[i-1][j]+arr2[i][j-1]-arr2[i-1][j-1];
        }

    }

    for( i=0;i<M;i++){
        cin >> insert1 >> insert2 >> insert3 >> insert4;

        for( j=insert1;j<=insert3;j++){
            result= arr2[insert3][insert4] -arr2[insert1-1][insert4]-arr2[insert3][insert2-1] +arr2[insert1-1][insert2-1];
        }
        cout << result <<'\n';
    }

    return 0;
}