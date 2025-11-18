#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int arr[130][130];
int b_result=0;
int w_result=0;

int loop(int len, int x, int y){
    int half= len/2;
    pair<int,int> loc[4]  = {{x,y},{x+half,y},{x,y+half},{x+half,y+half}};
    
    for(int k=0; k<4;k++){
        int b_cnt=0;
        int w_cnt=0;
        // cout << "loc x:" << loc[k].first<< " y:" << loc[k].second <<'\n';
        for(int i=loc[k].first;i<half+loc[k].first;i++){
            for(int j=loc[k].second;j<half+loc[k].second;j++){
                    b_cnt+= arr[i][j];
                if(arr[i][j]==0)
                    w_cnt++;
                // cout <<  arr[i][j]<<' ';
            }
            // cout <<'\n';
        }
        int require_v= half*half;
        // cout << "require_v: " << require_v<<'\n';
        if(b_cnt==require_v){
            // cout << "found Blue! "<<'\n';
            b_result++;
            continue;
        }else if(w_cnt==require_v){
            // cout << "found whilte! "<<'\n';
            w_result++;
            continue;
        }else{
            loop(half, loc[k].first, loc[k].second);
        }
    }
    
    return 0;
}

int main(){
    int n;
    cin >> n ;
    int w_cnt=0;
    int b_cnt=0;
    for(int i=0; i< n; i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
                b_cnt+= arr[i][j];
            if(arr[i][j]==0)
                w_cnt++;
        }
    }
    if(w_cnt== n*n ){
        cout << "1\n0";
        return 0;
    }else if(b_cnt == n*n){
        cout << "0\n1";
        return 0;
    }

    loop(n, 0,0);

    cout << w_result <<'\n'<<b_result;
}