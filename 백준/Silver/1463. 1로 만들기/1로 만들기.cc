#include <iostream>

using namespace std;

int main(){

    int x; 
    cin >> x;
    //1,000,000

     int arr[x+1];
     arr[0] = 0;
     arr[1] = 0;
     arr[2] = 1;
     arr[3] = 1;

      for(int i =4;i<=x;i++){
        int min = 1e9;

        if(i%3 ==0 && min>arr[i/3]+1)
            min = arr[i/3]+1;

        if((i-1)%3 == 0 && min>arr[(i-1)/3]+2)
            min = arr[(i-1)/3]+2;

        if((i-2)%3 == 0 && min>arr[(i-2)/3]+3)
            min = arr[(i-2)/3]+3;

        if((i)%2 ==0 && min >arr[(i/2)]+1)
            min =arr[(i/2)]+1;

        if((i-1)%2 == 0 && min > arr[(i-1)/2]+2)
            min = arr[(i-1)/2]+2;

        arr[i]=min;
        //cout << i << ": "<<arr[i]<<'\n';
      }

    cout << arr[x];
}