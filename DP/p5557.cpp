#include <bits/stdc++.h>
using namespace std;

long long arr[101];
long long N;

long long dp_table[101][21];




int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    long long x=arr[0];
    dp_table[0][x]=1;
    for(int i=1;i<N-1;i++){
        long long b= arr[i];
        for(int j=0;j<=20;j++){
            if(dp_table[i-1][j]!=0){
                int a = j;
                if(a+b<=20){
                    dp_table[i][a+b] += dp_table[i-1][j];
                }
                if(a-b >=0){
                    dp_table[i][a-b] += dp_table[i-1][j];
                }
            }
        }
    }

    cout << dp_table[N-2][arr[N-1]];

    
}