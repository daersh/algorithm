#include <bits/stdc++.h>

using namespace std;
int N;
int arr[100100];
int arr2[100100];
long long result;

int main(){
    cin >> N;
    if(N==1){
        cin >> arr[1];
        cout << 0;
        return 0;
    }

    for(int i=1;i<=N;i++){
        cin >> arr[i];
        arr2[i]=arr2[i-1]+arr[i];
        cout << arr2[i] << '\n';
    }
    
    for(int i=1;i<N;i++){
        int x = arr2[N] - arr2[i];
        printf("x = %d\n", x);
        result += arr[i]*x;
    }

    cout << result;
    return 0;
}