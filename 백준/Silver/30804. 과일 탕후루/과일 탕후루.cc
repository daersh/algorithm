#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n ;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    if(n==1){
        cout << 1;
        return 0;
    }
    int result=2;
    int cnt=2;
    pair<int,int> se={arr[0],arr[1]};
    for(int i=2;i<n;i++){
        if(arr[i] == se.first || arr[i] == se.second ){
            cnt++;
        }else if(arr[i] == se.first || se.second){
            cnt =2;
            int past_loc=i-1;
            se.first = arr[past_loc];
            se.second = arr[i];
            while(arr[past_loc]==arr[past_loc-1]){
                // cout << "past_loc: "<< past_loc << "\n";
                cnt++;
                past_loc--;
            }
        }
        result = max(result, cnt);
    }
    cout << result;
}