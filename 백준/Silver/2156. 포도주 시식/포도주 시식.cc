#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int n;
vector<long long> vec;
int arr[10015];
int arr1[10015];


int main(){
    cin >> n;
    
    for(int i=0; i< n; i++){
        int x;
        cin >>x;
        arr[i]=x;
    }
    long long sum =0;
    arr1[0]=arr[0];
    arr1[1]=arr[1]+arr[0];
    // 이전합, 
    arr1[2]= max(arr1[1], max( arr[0]+arr[2], arr[1]+arr[2] ));

    for(int i=3; i<n;i++){
        arr1[i]= max(arr1[i-1], max( arr1[i-2]+arr[i], arr1[i-3]+arr[i-1]+arr[i] ));
    }
    cout << arr1[n-1];
    
    return 0;

}

    /*
        0
    */ 

