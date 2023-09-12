#include <bits/stdc++.h>

using namespace std;
int N,M;

long long result;
int arr[301000];
int arr2[301000];
int maxi;
int count1;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    

    for(int i=1;i<=N;i++){
        cin >> arr[i];
        arr2[i]= arr2[i-1]+arr[i];
    }
    
    for(int i=M;i<=N;i++){
        if(arr2[i]-arr2[i-M]>maxi){
            maxi= arr2[i]-arr2[i-M];
            count1=1;
        }else if(arr2[i]-arr2[i-M]==maxi){
            count1++;
        }
    }
    if(maxi==0){
        cout << "SAD" ; return 0;
    }
    cout << maxi <<'\n' << count1;
    return 0;
}