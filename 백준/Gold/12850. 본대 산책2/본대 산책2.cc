#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
long long arr[8][8]= {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 0}
};
long long arr2[8][8];
long long mod = 1000000007;
long long result[8][8];

int main(){
    // 교차점 개수, 시작점, 끝점, 늦는 시간
    int n;
    cin >> n;
    // init
    for(int i =0;i<8;i++)
        result[i][i]=1;
    


    // 인접행렬
    while(n){
        if(n%2){
            for(int i =0; i < 8; i++){
                for(int j =0; j < 8; j++){
                    for(int k =0; k < 8; k++){
                        arr2[i][j] += result[i][k] * arr[k][j];
                        arr2[i][j] %= mod;
                    }
                }
            }
            for(int i =0; i < 8 ; i++){
                for (int j = 0; j < 8; j++)
                {
                    result[i][j] =arr2[i][j];
                    arr2[i][j]=0;
                }
            }
        }
        for(int i =0; i < 8; i++){
            for(int j =0; j < 8; j++){
                for(int k =0; k < 8; k++){
                    arr2[i][j] += arr[i][k] * arr[k][j];
                    arr2[i][j] %= mod;
                }
            }
        }
        for(int i =0; i < 8 ; i++){
            for (int j = 0; j < 8; j++)
            {
                arr[i][j] =arr2[i][j];
                arr2[i][j]=0;
            }
        }
        n/=2;
    }
    
    cout << result[0][0];
}
