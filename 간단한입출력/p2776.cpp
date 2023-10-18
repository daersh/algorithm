#include <iostream>
#include <algorithm>

using namespace std;



int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T;
    cin >>T ;
    for(int t=0;t<T;t++){
    int n,m;
    cin >> n;
    int arr1[n];
    for(int i=0;i<n;i++){
        cin >>arr1[i];
    }
    
    cin >> m;
    int arr2[m];
    for(int i=0;i<m;i++){
        cin >> arr2[i];
    }
    sort(arr1,arr1+n);

    for(int i=0;i<m;i++){
        int x= arr2[i];
        int l=-1, r=n;
        while(l+1<r){
            int mid= (l+r)/2;
            //cout << "mid:"<<mid <<'\n';
            if(x<arr1[mid]){
                r=mid;
            }else if(x>arr1[mid]){
                l=mid;
            }else if(x==arr1[mid]){
                x=0;
                break;
            }
        }
        if(x==0){
            cout << "1\n";
        }else{
            cout << "0\n";
        }
    }
    }
}