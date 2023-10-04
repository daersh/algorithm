#include <iostream>
using namespace std;

int main(){
    int N;
    int arr[100][100]={0};
    cin >>N;
    int x,y;
    for(int i=0;i<N;i++){
        cin >>x>>y;
        for(int j=x;j<x+10;j++){
            for(int k=y;k<y+10;k++){
                arr[j][k]=1;
            }
        }
    }
    int cnt=0;

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(arr[i][j]==1){
                cnt++;
            }
        }
    }
    cout << cnt;
}