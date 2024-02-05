#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    int cnt=0;
    for(int i=0; i< n; i++){

        cin >> arr[i];
        if(arr[i]==1)cnt++;
    }

    sort(&arr[0],&arr[n]);

    long long sum=0;
    int minus_loc = 0;
    int plus_loc = n-1;
    
    while (arr[minus_loc]<=0 && minus_loc<n)
    {
        int x =arr[minus_loc];
        // cout << "x: "<<x <<'\n';
        minus_loc++;
        if(arr[minus_loc]<=0 && minus_loc<n){
            int y = arr[minus_loc];
            sum+= x* y ;
            minus_loc++;
                        // cout << "x: "<<x <<"  y: "<<y<<'\n';
            if(y==0) break;
        }else{
            sum+=x;
            break;
        }
    }

    // cout <<' '<<sum<<'\n';
    while(arr[plus_loc]>1 && plus_loc>=0)
    {
        int x= arr[plus_loc];
            // cout << "x: "<<x <<'\n';        
        plus_loc--;

        if(arr[plus_loc] > 1 && plus_loc>=0){
            int y = arr[plus_loc];
            sum+= x*y;
            // cout << "x: "<<x <<"  y: "<<y<<'\n';
            plus_loc--;
        }else{
            sum+=x;
            break;
        }
    }
    // cout << sum<<'\n';
    cout << sum+cnt;
    
    
}