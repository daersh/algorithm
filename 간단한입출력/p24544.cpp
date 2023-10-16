#include <iostream>

using namespace std;

int arr[1010];
int main(){
    int n,x,sum=0;
    cin >> n;
    for(int i=1;i<n+1;i++){
        cin >> arr[i];
        sum+=arr[i];
    }

    cout << sum<<'\n';
    sum=0;
    for(int i=1;i<n+1;i++){
        cin >> x ;
        if(x==0) sum+=arr[i];
        
    }
    cout << sum;
}