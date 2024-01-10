#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T;
    cin >> T;
    for(int t=0;t<T;t++)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i< n; i++){
            cin >> arr[i];
        }
        int max= -1e9;
        int sum=0;
        for(int i=0; i< n; i++){
             
            sum+=arr[i];

            if(max<sum){
                max=sum;
            }

            if(sum<0){
                sum=0;
            }
            
        }
        cout << max <<'\n';
    }
    
}
