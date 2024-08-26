#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    int n ;
    cin >> n;
    int arr[10001];
    
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    sort(&arr[0],&arr[n]);
    int cnt =0;
    for(int i =0; i < n; i++){
        int l = i;
        if(arr[l]>0)
            break;

        for(int j = n-1; j >i; j--){
            int r= j;
            if(arr[r]<0) 
                break;
            int sum = arr[l]+arr[r];
            cout << "l: "<< arr[l]<<" r: "<< arr[r]<<' ';
            
            l++;
            r--;

            while(l+1<r){
                int mid = (l+r)/2;
                int midV = arr[mid];
                
                if(midV+sum<0)
                    l=mid;
                else    
                    r=mid;
            }

            cout << "changed l: " << arr[l] << " r: " << arr[r] <<'\n';
            
            int lVal = arr[l];
            int rVal = arr[r];
            if(sum+lVal==0|| sum+rVal==0){
                cout << "lVal: " << lVal << "rVal: " << rVal <<'\n';
                cnt++;
            }

        }

    }
    cout << cnt;

    return 0;
}