#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >>n;
    int arr[41]={0};
    arr[0]=0;
    arr[1]=1;
    
    for(int i=2;i<=40;i++){
        arr[i]= arr[i-1]+arr[i-2];
    }
    for(int i=0; i<n;i++){
        int m;
        cin >> m;
        if(m==0){
            cout << "1 0\n";
            continue;
        }
        cout << arr[m-1] <<' '<<arr[m]<<'\n';
    }
    return 0;
}