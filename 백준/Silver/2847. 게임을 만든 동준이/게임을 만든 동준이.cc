#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n;i++) {
        int x;
        cin >>x;
        arr[i] = x;
    }

    int cnt=0;
    int start_v=arr[n-1];
    for(int i=n-2;i >=0;i--){
        int x=0;
        if(start_v<=arr[i]){
            x= arr[i]-start_v+1;
            cnt+=x;   
        }
        // cout << cnt << endl;
        start_v = arr[i]-x;
    }
    cout << cnt << endl;
    return 0;
    


}