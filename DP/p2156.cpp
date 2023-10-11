#include <iostream>
using namespace std;

int arr[10010];


int dp(int start){
    if(start==1 ||start==0){
        return arr[start];
    }
    if(arr[start-1]>arr[start-2]){
        return arr[start]+ dp(start-1);
    }else{
        return arr[start]+ dp(start-2);
    }
}

int main(){
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    if(N==1){
        cout << arr[0];
        return 0;
    }
    int x,y,z,a;

    x= dp(N);
    y= dp(N-1);
    z= dp(N-2);
    a= dp(N-3);
    if(x>=y&&x>=z && x>=a){
        cout << x;
    }else if(y>=x &&y>=z && y>=a){
        cout << y;
    }else if(a>=x&&a>=y&&a>=z){
        cout << a;
    }
    else {
        cout << z;
    }


}