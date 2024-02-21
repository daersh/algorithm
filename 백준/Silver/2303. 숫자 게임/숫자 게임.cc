#include <iostream>
#include <queue>


using namespace std;
int result[1010];

int main(){
    int n;
    cin >> n ;
    int arr[n][5];
    for(int i=0; i< n;i++){
        for(int j=0; j<5;j++)
            cin >> arr[i][j];
    }
    
    for(int t=0;t<n;t++){
        for(int i=0; i<5;i++){
            for(int j=i+1;j<5;j++){
                for(int k=j+1;k<5;k++){
                    int x = arr[t][i]+arr[t][j]+arr[t][k];
                    if(result[t]%10 ==x%10){
                        if(result[t]<x){
                            result[x]=x;
                        }
                    }else if(result[t]%10 <x%10 ){
                        result[t]=x;
                    }
                }   
            }
        }
    }
    int ans = 0;
    int loc = 0;

    for (int i = 0; i < n; i++)
    {
        if(ans%10 == result[i]%10 ){
                loc=i+1;
        }else if(ans%10<result[i]%10){
            ans= result[i];
            loc=i+1;
        }
    }
    cout << loc;
}
