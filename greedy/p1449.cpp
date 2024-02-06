#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n , m;
    cin >> n >> m;
    int arr[n];
    for(int i=0; i< n ;i++){
        cin>> arr[i];
    }
    sort(&arr[0],&arr[n]);
    int min =0 ;
    int cnt =0;
    for(int i=0; i< n ; i++){
        if(arr[i]>min){
            min= arr[i]+m-1;
            cnt++;
        }
    }

    cout <<cnt;
}