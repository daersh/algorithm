#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        int n,m;
        cin >> n >> m;
    
        int arr[n];
        int cnt=0;
        int result=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i]>=m){
                cnt+=arr[i];
                arr[i]=0;
            }else if(arr[i]==0 && cnt>0){
                cnt--;
                result++;
                arr[i]=1;
            }
        }
        cout << result << endl;

    }
}