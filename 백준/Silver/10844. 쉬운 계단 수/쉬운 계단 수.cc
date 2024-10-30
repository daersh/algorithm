#include <iostream>

using namespace std;


int main(){

    int n;
    cin >> n;

    long long arr[10];
    arr[0]=0;

    for(int i=1; i<10; i++){
        arr[i]=1;
    }

    // 1 2 3 4 5 6 7 8 9
    // 10 12 21 23 32 34 43 45 54 56 65 67 76 78 87 89 98
    // 101 121 123
    // 210 212 232 234 
    // 321 323 343 345
    // 432 434 454 456
    // 543 545 565 567
    // 654 656 676 678
    // 765 767 787 789
    // 876 878 898 
    // 987 989 

    long long dp[10];

    for(int i=1; i<n; i++){
        for(int j=0; j<=9; j++)
            dp[j]=0;

        for(int j=0; j<=9;j++){

            if(j==0){
                dp[j+1]=(dp[j+1]+arr[j]);
            }else if(j==9){
                dp[j-1]=(dp[j-1]+arr[j]);
            }
            else{
                dp[j-1]=(dp[j-1]+arr[j]);
                dp[j+1]=(dp[j+1]+arr[j]);
            }
        }

        for(int j=0;j<=9;j++)
            arr[j]=dp[j]%1000000000;

    }

    long long result=0;
    for(int i =0;i<=9;i++){
        // cout << arr[i]<< ' ';
        result+=arr[i];
    }

    cout << result%1000000000;

}