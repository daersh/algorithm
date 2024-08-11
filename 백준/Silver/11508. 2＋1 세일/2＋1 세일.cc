#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n ;

    cin >> n;
    int arr[n];

    for(int i= 0 ; i < n ; i++){
        cin >> arr[i];
    }
    sort(&arr[0],&arr[n]);
    int e = n;
    int sum = 0;
    if(n==1){
        cout << arr[0];
        return 0;
    }


    for(int i = n-1;i >=2;i-=3){
        sum += arr[i]+arr[i-1];
        e=i-3;
    }



    if(e==1){
        sum += arr[e]+arr[e-1];
    }else if(e==0){
        sum += arr[e];
    }

    cout << sum;

    return 0;

}


