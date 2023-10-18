#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    auto check = [&](int jeol) {
        long long sum=0;
        for(int i =0; i < n; i++) {
            if(arr[i]>jeol){
                sum+=arr[i]-jeol;
            }
        }
        return sum >= m;
    };

    int l=0, r=1e9;
    while(l+1<r){
        int mid= (l+r)/2;
        if(check(mid)){
            l=mid;
        }else{
            r=mid;
        }
    }
    cout << l;
}