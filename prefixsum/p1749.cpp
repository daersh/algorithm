#include <iostream>
using namespace std;



int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    int max=-1e9;
    int arr[210][210]={0,};

    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
            if(arr[i][j]>max) max=arr[i][j];

            arr[i][j]= arr[i][j]+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
            if(arr[i][j]>max) 
                max= arr[i][j];
        }
    }


 

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
            for(int k=0;k<i;k++){
                for(int l=0;l<j;l++){

                    int x= arr[i][j]-arr[i-k-1][j]-arr[i][j-l-1]+arr[i-k-1][j-l-1];
                    if(x>max) max=x;
                }
            }
        }
    }
    cout << max;
}
