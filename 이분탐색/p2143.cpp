#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    long long val;
    int n,m;
    cin >> val;
    cin >> n;
    long long arr1[n+1];
    arr1[0]=0;
    for(int i=1;i<=n;i++){
        cin >> arr1[i];
    }
    cin >> m;
    long long arr2[m+1];
    arr2[0]=0;
    for(int i=0;i<=m;i++){
        cin >> arr2[i];
    }
    for(int i=1;i<=n;i++){
        long long start= arr1[i]-arr1[i-1];
        if(start>=val)break;

        for(int j=i+1;i<=n;i++){
            long long sum=
        }
    }

}