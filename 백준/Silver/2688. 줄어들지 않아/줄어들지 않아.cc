#include <iostream>

using namespace std;
long long result1[65];

int main(){

    int n;
    cin >> n;

    long long arr[11]; 
    arr[0]=0;

    for(int i=1; i<=9; i++){
        arr[i]=1;
    }
    
    long long result=10;
    result1[1]=10;
    for(int i=2; i<65; i++){
        for(int j=1; j<=9; j++){
            arr[j]=(arr[j]+arr[j-1]);
            result+=arr[j];
        }

        result1[i] = result;
        // cout << i<<": "<< result << endl;
    }


    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        
        cout << result1[x] << '\n';
    }
    
    
}