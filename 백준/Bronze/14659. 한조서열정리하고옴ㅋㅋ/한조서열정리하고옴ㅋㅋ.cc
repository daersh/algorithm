#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n ;
    int arr[n];
    int result=0;
    int cnt=0;

    cin >> arr[0];
    int past=arr[0];
    for (int i = 1; i < n; i++){
        cin >> arr[i];
        if(arr[i]<past){
            cnt++;
        }else{
            result = max(result,cnt);
            cnt=0;
            past= arr[i];
        }
    }

    cout << max(result,cnt);
    
}