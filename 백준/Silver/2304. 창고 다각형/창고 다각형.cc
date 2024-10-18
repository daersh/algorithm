#include <iostream>

using namespace std;

int arr[1010];
int arr2[1010];

int main(){

    int N;
    cin >> N;
    int x,y;
    int start=1100;
    int end=0;
    int x_max=0;
    int y_max=0;

    for(int i=0;i<N;i++){
        cin >> x>>y;
        if(end<x){
            end=x;
        }
        if(start>x){
            start=x;
        }
        //x가 1000까지 다 돌지 않도록 하기 위함
        if(y>=y_max){
            x_max=x;
            y_max=y;
        }

        arr[x]=y;
    }

    for(int i=start;i<x_max;i++){
        
        if(arr[i]==0)continue;
        if(arr[i]>arr2[i])
            fill(&arr2[i],&arr2[x_max],arr[i]);
    }
    for(int i=end;i>x_max;i--){
        if(arr[i]==0)continue;
        if(arr[i]>arr2[i]){
            fill(&arr2[x_max+1],&arr2[i+1],arr[i]);
        }
    }
    arr2[x_max]=y_max;
    int sum=0;
    for(int i=start;i<=end;i++){
        //cout << arr2[i]<<' ';
        sum+=arr2[i];
    }
    //cout << '\n';
    cout << sum;
}