#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int INF = 1e9;
int n; 
int arr[2010]; 
int used[2010];

int lowerbound(int val, int loc){
    
    int l= 0;
    int r= n;
    while(l+1<r){
        int mid = (l+r)/2;
        if(mid<val){
            l= mid;
        }else{
            r= mid;
        }
    }
    if(l!=loc && arr[r]==val){
        return r;
    }else {
        return l;
    }
}

int main(){
    cin >> n;
    int zero=0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i]==0){
            zero++;
        }
    }
    if(n==2) {
        cout << 0;
        return 0;
    }
    sort(&arr[0],&arr[n]);
    int cnt =0;
    //start
    for(int i = 0; i< n-1; i++){
        for(int j=i+1; j<n;j++){
            //cout << '['<<i<<','<<j<<']' <<'\n';
            int val = arr[j]+arr[i]; 
            if(arr[i]<0 && arr[j]<0){
                val= arr[i]-arr[j];
            }
            if(val>arr[n-1] ) break;
            if(used[val]==1)continue;
            int loc = lowerbound(val,j);
            
        }
    }
    if(zero>1){
        cnt+=zero-1;
    }
    cout << cnt;

}