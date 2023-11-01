#include<iostream>

using namespace std;

int n;
int arr[2010];
int arr2[2010];

int main(){
    cin >>n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        arr2[i]=0;
    }
    sort(arr,arr+n);
    int end= arr[n-1];
    
    int cnt=0;
    cout << "start\n";
    for(int i=0;i<n-2;i++){
        int x=arr[i];
        cout << x << '\n';
        for(int j=i+1;j<n;j++ ){
            int y= arr[j];
            if(x+y>end)break;
            else {
                
                
            }
        }
    }
    for(int i=0;i<n;i++){
        if(arr2[arr[i]]==true){
            cnt++;
        }
    }
    cout << cnt;
    
}