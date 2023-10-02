#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    int cnt=0;

    for(int i=0;i<n;i++){
        string a;
        int arr[26]={0};
        cin >> a;
        int tf=false;

        for(int j=0;j<a.size();j++){
            if(arr[a[j]-97]!=0 && a[j]!=a[j-1]){
                tf=true;
                break;
            }
            arr[a[j]-97]++;
            
        }

        if(tf==false){
            cnt++;
        }
    }
    cout << cnt;
}