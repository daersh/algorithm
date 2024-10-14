#include <bits/stdc++.h>

using namespace std;

int N,M;
long long arr[1000100];

long long cnt[1000100];
long long result;
int i;

int main(){
    
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> N >> M;
    
    for( i=1;i<=N;i++){

        cin >> arr[i];

        arr[i]=arr[i]+ arr[i-1];
    
        cnt[arr[i]%M]++;

        if(arr[i]%M==0) {
            result ++;
        }

    }

    for( i=0;i<M;i++){
        result += cnt[i]*(cnt[i]-1)/2;

    }
    
    cout << result;
        
}