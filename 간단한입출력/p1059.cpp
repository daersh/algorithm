#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

int main(){
    int s,l;
    cin >> s;
    int arr[s];
    
    for(int i=0;i<s;i++)    {
        cin >> arr[i];
    }
    sort(arr,arr+s);
    cin >> l;
    int start=0,end=0;
    if(l<arr[0]){
        start=1;
        end=arr[0]-1;
    }else{
    for(int i=0;i<s-1;i++){
        if(l==arr[i] || l== arr[i+1]){
            cout << 0;
            return 0;
        }
        if(l>arr[i] && l<arr[i+1]){
            start=arr[i]+1;
            end=arr[i+1]-1;
        }
    }
    }

    int sum=0;
    if(start==l){
        sum= end-start;
    }else if(l==end){
        sum= end-start;
    }else{
        sum= (end-l+1)*(l-start+1)-1;
    }

    cout << sum;

}