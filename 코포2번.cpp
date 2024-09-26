#include <iostream>

using namespace std; 

int main(){
    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        int n;
        cin >> n;
        int arr[n];
        int avg=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            avg+=arr[i];
        }
        avg/=n;
        int p = 0;
        for(int i=0; i<n; i++){
            if(avg>arr[i])
                p++;
        }

        if(p*2>= n){
            int l=0;
            int r=1e9;
            while(l+1<r){
                int sum=0;
                int mid = (l+r)/2;

                for(int i=0; i<n; i++){
                    if(mid<arr[i]){
                        sum += mid;
                    }
                }

                for(int i=0; i<n; i++){
                    if(arr[i]<avg){
                        int x =avg-arr[i];
                        if(x<=sum)
                            sum-= x;
                        else{
                            l=mid;
                        }
                            
                    }
                    
                }

            }

        }else
            cout << -1<<'\n';
        
    }
}