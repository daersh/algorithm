#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int arr[n+1];
    for(int i=1;i<n+1;i++){
        arr[i]=i;
    }

    for(int i =0;i<m;i++){
        int x,y;
        cin >> x >>y;
        while(x<y){
            int temp=arr[x];
            arr[x]= arr[y];
            arr[y]=temp;
            x++;
            y--;
        }
    }
    for(int i=1;i<n+1;i++)
        cout << arr[i] << ' ';
}