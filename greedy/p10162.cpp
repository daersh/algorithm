#include <iostream>

using namespace std;

int main(){
    long long n;
    cin >>n;
    int x= 300;
    int y= 60;
    int z= 10;
    int arr[3];
    arr[0] = n/300;
    n = n%300;
    arr[1] = n/60;
    n = n%60;
    arr[2] = n/10;
    n = n%10;
    if(n!=0){
        cout << -1;
    }else{
        cout << arr[0]  << ' ' << arr[1] << ' ' << arr[2];
    }
}