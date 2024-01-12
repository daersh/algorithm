#include <iostream>
#include <map>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    map<int,int> result;
    int arr[n+1];
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        result[arr[i]]++;
    }
    
    int s=arr[1];
    int e=arr[n];
    

    cout << result[m];
}