#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n;i++){
        int a;
        cin >> a;
        // a*=100;

        int arr[4];
        arr[0] = a/25;
        a%=25;
        arr[1] = a/10;
        a%=10;
        arr[2] = a/5;
        a%=5;
        cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << ' ' << a << endl;
    }
}