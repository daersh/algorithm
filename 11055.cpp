#include <iostream>

using namespace std;

int arr[1010];
int arr2[1010];

int main(){

    int n ;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    arr2[0]= arr[0];
    int result = arr2[0];

    for(int i =1; i < n ; i++){
        arr2[i] = arr[i];

        for(int j =i-1; j >= 0; j--){
            if(arr2[i] > arr[j]) {
                arr2[j] += arr2[j];
            }
        }
        

        if(arr2[i] > result) {
            result = arr2[i];
        }

    }

    cout << result;

}