#include <iostream>

using namespace std;

int main(){
    int arr[6]= {1,1,2,2,2,8};

    for(int i = 0 ; i < 6 ; i++){
        int x;
        cin >> x;
        arr[i] -=x;
        cout << arr[i] << ' ';
    }
}