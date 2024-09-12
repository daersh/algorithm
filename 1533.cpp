#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
long long arr[60][60];
long long arr2[60][60];
long long mod = 1000003;
long long result[60][60];

int main(){
    // 교차점 개수, 시작점, 끝점, 늦는 시간
    int n, s, e, t;
    cin >> n >> s >> e >> t;
    // init
    for(int i =0;i<60;i++)
        result[i][i]=1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){ 
            char c;
            cin >> c;
            arr[i][j] = c-'0';
        }
    }
    // 
    for(int i = 0; i < n; i++){
        arr[40+i][30+i] =1;
        arr[30+i][20+i] =1;
        arr[20+i][10+i] =1;
        arr[10+i][i] =1;
        for(int j = 0; j <n; j++){
            if(arr[i][j]==2){
                arr[i][j]=0;
                arr[i][10+j] = 1;
            }else if(arr[i][j]==3){
                arr[i][j]=0;
                arr[i][20+j] = 1;

            }else if(arr[i][j]==4){
                arr[i][j]=0;
                arr[i][30+j] = 1;

            }else if(arr[i][j]==5){
                arr[i][j]=0;
                arr[i][40+j] = 1;
            }
        }
    }
    // 인접행렬
    while(t){
        if(t%2){
            for(int i =0; i < 60; i++){
                for(int j =0; j < 60; j++){
                    for(int k =0; k < 60; k++){
                        arr2[i][j] += result[i][k] * arr[k][j];
                        arr2[i][j] %= mod;
                    }
                }
            }
            for(int i =0; i < 60 ; i++){
                for (int j = 0; j < 60; j++)
                {
                    result[i][j] =arr2[i][j];
                    arr2[i][j]=0;
                }
            }
        }
        for(int i =0; i < 60; i++){
            for(int j =0; j < 60; j++){
                for(int k =0; k < 60; k++){
                    arr2[i][j] += arr[i][k] * arr[k][j];
                    arr2[i][j] %= mod;
                }
            }
        }
        for(int i =0; i < 60 ; i++){
            for (int j = 0; j < 60; j++)
            {
                arr[i][j] =arr2[i][j];
                arr2[i][j]=0;
            }
        }
        t/=2;
    }
    
    cout << result[s-1][e-1];
}
