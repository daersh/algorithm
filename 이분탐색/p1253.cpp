#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n; 
//배열, 시작값, 끝 위치
bool eboon(long long arr[], int start, int end){
    
    long long end_val= arr[end];
    long long start_val= arr[start];

    int l= 0;
    int r= n;
    while(l+1<r){
        int mid= (l+r)/2;
        if(end_val - start_val>mid){
            l=mid;
        }else{
            r=mid;
        }
    }
    cout << arr[end]<<"= "<<start_val << '+' <<arr[l]  << "or" << arr[r]<<'\n';

    if(start_val+arr[l]==end_val && l!=end && l !=start){
        cout << start_val << ' ' <<arr[l]<<'\n';
        return true;
    }else if(start_val+arr[r]==end_val && r!=end && r!=start){
        cout << start_val << ' ' <<arr[r]<<'\n';
        return true;
    }else{
        return false;
    }
}

int main(){
    cin >> n;
    long long arr[n];
    int zero=0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i]==0){
            zero++;
        }
    }

    sort(&arr[0],&arr[n]);

    int cnt = 0;
    if(zero>2){
        cnt+=zero;
    }
    for(int i=0;i<n;i++){
        long long val = arr[i];
        int loc=i;
        for(int j=0;j<n;j++){
            if(j==i) continue;
            if(eboon(arr,j,i)==true){
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
}