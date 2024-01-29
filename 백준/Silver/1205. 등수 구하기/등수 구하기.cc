#include <iostream>

using namespace std;

int main(){
    int n, score, p;
    cin >> n >> score >> p;
    int arr[p+1];
    int arr2[p+1];
    int rank=1;
    arr[0]=-1;
    for(int i=0; i<=p;i++){
        arr2[i]=i;
    }
    for(int i=1; i<=n ;i++){
        cin >> arr[i];
        if(arr[i]==arr[i-1]){
            arr2[i]=arr2[i-1];
        }else {
            arr2[i]=i;
        }
    }
    int l=1;
    int r=n+1;
    while(l+1<r){
        int mid = (l+r)/2;
        if(score<=arr[mid]) l=mid;
        else r= mid;
    }

    //cout << l <<' '<<r<<'\n';
    if(n==0 ) {
        cout << 1 ; return 0;
    }
    if(r>p){
        cout << -1 ; return 0;
    }
    if(score >= arr[r-1]){
        cout << arr2[r-1];
    }else{
        cout << arr2[r];
    }

}