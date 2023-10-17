#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long n , m;
    cin >> n>> m; 
    long long arr[m+1];
    arr[0]=0;
    for(int i=1;i<=m;i++){
        cin >> arr[i];
        arr[i]+=arr[i-1];
    }

    for( int i=0;i<n;i++){
        long long x;
        cin >> x;
        
        long long y= lower_bound(arr,&arr[m+1],x)- arr;
        
        if(y==m+1){
            cout <<"Go away!\n";
        }else{
            cout << y<<'\n';
        }
    }
}