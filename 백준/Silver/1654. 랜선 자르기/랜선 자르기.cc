#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    long long n,m;
    cin >> n >> m;
    long long arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(&arr[0],&arr[n]);

    long long l= 1;
    long long r= arr[n-1];
    long long result=0;
    while(l+1<r){
        
        long long cnt=0;
        long long mid= (l+r)/2;

        for(int i=0; i< n; i++){
            cnt+= arr[i]/mid;
        }
        if(cnt<m){
            r=mid;
        }else{
            l=mid;
        }
    }
    
    long long cnt=0;
    for(int i=0; i< n; i++){
        cnt+= arr[i]/r;
    }
    if(cnt==m){
        cout << r;
    }else{
        cout << l;
    }
    

}