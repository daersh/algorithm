#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long val;
    int n,m;
    long long cnt=0;
    map<long long,long long> find;

    cin >> val;
    cin >> n;
    
    long long arr1[n+1];
    arr1[0]=0;
    for(int i=1;i<=n;i++){
        cin >> arr1[i];
        arr1[i]+=arr1[i-1];
    }

    cin >> m;
    long long arr2[m+1];
    arr2[0]=0;

    for(int i=1;i<=m;i++){
        cin >> arr2[i];
        arr2[i]+=arr2[i-1];
    }

    for(int i=1;i<=n;i++){
        long long start = arr1[i];

        for(int j=0;j<i;j++){
            long long cmp = start-arr1[j];
            find[cmp]++;
        }
    }


    for(int i=1;i<=m;i++){
        long long start2= arr2[i];
        for(int j=0;j<i;j++){
            long long cmp = start2-arr2[j];         
            if(find[val-cmp]!=0){
                cnt+=find[val-cmp];
            }
        }
    }

    cout << cnt;
}
