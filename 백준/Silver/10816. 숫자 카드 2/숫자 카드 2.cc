#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    map<int,int> result;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    cin >> m;
    int arr2[m];
    for(int i=0; i< m; i++){
        cin >> arr2[i];
    }  
    int arr3[m];
    for(int i=0; i< m; i++){
        arr3[i]=arr2[i];
    }
    sort(&arr2[0],&arr2[m]);
    for(int i=0;i<n;i++){
        int val = arr[i];
        int l=0;
        int r=m;

        while(l+1<r){
            int mid= (l+r)/2;
            if(arr2[mid]<val){
                l=mid;
            }else{
                r=mid;
            }
        }
        if(arr2[l]==val || arr2[r]==val) 
        {
            result[val]+=1;
        }
    }
    for(int i=0; i< m;i++){
        cout << result[arr3[i]]<< ' ';
    }
}