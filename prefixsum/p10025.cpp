#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >>m;
    int max=0;
    int arr[1000010]={0};
    int x,y;
    int max_len= 0;
    for(int i=0;i<n;i++){
        cin >>x >>y;
        if(max_len<y){
            max_len=y+3;
        }
        if(y<m){
            arr[0]+=x;
        }
        else {
            arr[y-m]+=x;
            }
        if(y+m+1>1000001){
            arr[1000001]+=-x;
        }
        else arr[y+m+1]+=-x;
    }
    for(int i=1;i<max_len;i++){
        arr[i]+=arr[i-1];
        if(max<arr[i]){
            max=arr[i];
        }
    }
    cout << max;
}