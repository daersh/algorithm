#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int arr[102][102];

int main () {
    int n,l;
    cin >> n >> l;
    int count =0;
    for(int i=1; i<=n; i++)
        for(int j =1; j<=n;j++)
            cin >> arr[i][j];
    
    // 가로
    for(int x=1; x<=n;x++){
        bool flag= false;
        
        int temp[n+1];
        for(int i=0;i<=n;i++)
            temp[i]=0;

        for(int y=2;y<=n;y++){

            int past = arr[x][y-1];
            int curr = arr[x][y];

            if(past==curr) continue;

            // 내리막인경우
            if(past-curr==1){
                if(y+l>n+1){
                    flag=true;
                    break;
                }
                for(int i=y; i<y+l;i++){
                    int next = arr[x][i];
                    if(curr!=next) flag=true;
                    temp[i]=1;
                }
            }else if(past-curr==-1){
                if(y-l<1){
                    flag=true;
                    break;
                }
                for(int i=y-1;i>=y-l;i--){
                    int next = arr[x][i];
                    if(past!=next || temp[i]==1) flag=true;

                    temp[i]=1;
                }
            }else if(abs(past-curr)>1) 
                flag=true;

            if(flag) break;

        }

        if(!flag) {
            // cout<< x<<"줄 확인\n";
            count++;
        }
    }

    // 가로
    for(int y=1; y<=n;y++){
        bool flag= false;
        
        int temp[n+1];
        for(int i=0;i<=n;i++)
            temp[i]=0;

        for(int x=2;x<=n;x++){

            int past = arr[x-1][y];
            int curr = arr[x][y];

            if(past==curr) continue;

            // 내리막인경우
            if(past-curr==1){
                if(x+l>n+1){
                    flag=true;
                    break;
                }

                for(int i=x; i<x+l;i++){
                    int next = arr[i][y];
                    if(curr!=next) flag=true;
                    temp[i]=1;
                }
            }else if(past-curr==-1){

                if(x-l<1){
                    flag=true;
                    break;
                }

                for(int i=x-1;i>=x-l;i--){
                    int next = arr[i][y];
                    if(past!=next || temp[i]==1) flag=true;

                    temp[i]=1;
                }
            }else if(abs(past-curr)>1) 
                flag=true;

            if(flag) break;

        }

        if(!flag) {
            // cout<< y<<"줄 확인\n";
            count++;
        }
    }


    cout << count;
    return 0;
}