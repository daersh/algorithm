#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    string n;
    cin >> n;
    int arr[n.length()];
    int sum=0;
    int find_zero=0;
    for(int i=0;i<n.length();i++){
        arr[i]= n[i]-'0';
        if(arr[i]==0) find_zero++;
        sum+=arr[i];
        
    }
    sort(&arr[0],&arr[n.length()]);
    if(sum%3!=0 || find_zero==0){
        cout << -1;
        return 0;
    }else{
        for(int i=n.length()-1; i>=0;i--){
            cout<<arr[i];
        }
    }
}
