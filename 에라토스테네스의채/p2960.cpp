#include <iostream>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int arr[n+1];
    for(int i=2;i<=n;i++){
        arr[i]=i;
    }
    int cnt=0;
    for(int i=2;i<=n;i++){
        if(arr[i]==-1){
            continue;
        }
        for(int j=i;j<=n;j++){

            if(j%i==0 && arr[j]!= -1){
                cnt++;
                arr[j]=-1;
                if(cnt==k){
                    cout << j;
                    return 0;
                }
            }
        }
    }
}