#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i< n ;i++){
        cin >> arr[i];
    }
    sort(&arr[0],&arr[n]);
    int max = arr[n-1];
    int result = 0;
    for(int i=0; i<n;i++){
        if(arr[i]*(n-i)>result) result= arr[i]*(n-i);
    }
    cout << result;
    /*
        10 15 : 20
        10 20 : 20
        1 2  : 2
        2 3 : 4
        3 4 : 6
        n = 2 최소의 2배
        4 5 6 : 10 12

    */

}