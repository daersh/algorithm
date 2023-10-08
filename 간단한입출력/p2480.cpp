#include <iostream>
using namespace std;

int main(){
    int x,y,z=0;
    int arr[7]={0};
    int max=0;
    for(int i=0;i<3;i++){
        cin >> x;
        arr[x]++;
        if(arr[x]==3){
            cout << 10000+ x*1000;
            return 0;
        }else if(arr[x]==2){
            y=x;
            z=2;
        }
        if(max<x){
            max=x;
        }
    }
    
    if(z==2){
        cout << 1000+ y*100;
    }else{
        cout << max*100;
    }



}