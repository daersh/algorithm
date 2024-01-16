#include <iostream>
using namespace std;

int main(){
    int n;
    cin >>n;
    int arr[n+1];
    arr[0]=0;
    for(int i=2;i<=n;i++){
        cin >> arr[i];
    }
    cin >> arr[1];
    for(int i=1;i<=n;i++){
        arr[i]+=arr[i-1];
    }
    int max=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int x,y,z;
            x= arr[i]+ arr[n]-arr[j];
            y= arr[j]-arr[i];
            if(x>y){
                z=y;
            }else{
                z=x;
            }
            if(max<z){
                max=z;
            }
        }
    }
    cout << max;

}