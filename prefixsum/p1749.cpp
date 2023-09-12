#include <bits/stdc++.h>

using namespace std;
int N,M,L;

int arr[1010][1010];
int arr2[1010][1010];
int cmp[1000];

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> N >> M;
    int i,j;
    int result=0;
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            cin >> arr[i][j];
        }
    }


    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
           if(cmp[j-1]+arr[i][j]>arr[i][j]) cmp[j]= cmp[j-1]+arr[i][j];
           else cmp[j] = arr[i][j];
        }
        for(int i=1;i<=M;i++){
            result= max( result , cmp[i]);
        }
    }
    cout <<result;
   
}