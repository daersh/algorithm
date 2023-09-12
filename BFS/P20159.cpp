#include <bits/stdc++.h>

using namespace std;
int N;
int sum;
int arr[100000];
int you[50100];
int me[50100];
int max_val;
int loc;

int main(){
    cin >> N;
    int i, x=0;
    for(i=1;i<=N; i++){
        cin >> arr[i];
        me[x]+=arr[i];
        i++;
        cin >> arr[i+1];
        you[x]+=arr[i+1];
        x++;
        if(arr[i-1]<arr[i]){
            if(arr[i]-arr[i-1]>max_val){
                max_val= arr[i+1]-arr[i];
                loc=x-1;
            }
        }
    }

}