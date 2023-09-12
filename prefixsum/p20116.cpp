#include <bits/stdc++.h>

using namespace std;
int N,M,L;

double arr[1000000];
double arr2[1000000];
int y;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    //N: 상자 개수
    //L: 상자 사이즈
    cin >> N >> L;
    int i;
    double result;

    if(N==1){
        cin >> i;
        cout << "stable";
        return 0;
    }

    for(i=1;i<=N;i++){

        cin >> arr[i];

        int x= arr[i]-arr[i-1];
        //중심 : 상자위치, 2*사이즈-사이즈
        if(x<0){
            x=-x;
        }
        if(x >= 2*L ){
            //cout << "상자 위치 벗어남 \n";
            y=true;
            continue;
        }
        arr2[i]= arr[i]+ arr2[i-1];
    }


    if(y!=true){
        for(i=1;i<N;i++){

            result = (arr2[N]-arr2[i])/(N-i);

            //cout << "result: " << result <<'\n';
    
            if( result<= arr[i]-L || result>= arr[i]+L  ){
                y=true;
                break;
            }
        }
    }

    if(y==true){
        cout << "unstable";

    }else{
        cout << "stable";
    }
    return 0;
}