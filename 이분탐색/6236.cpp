#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n , m;

    cin >> n >> m;
    vector<int> vec;
    int minVal = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vec.push_back(x);
        minVal = max(minVal, x);
    }

    int l = minVal;
    int r = 1e9; 
    int result=1e9;

    while(l+1 < r){
        int mid = (l+r)/2;
        int cnt =0;
        int sum = 0;
        for(int i = 0; i < n;){
            int x = vec[i];
            if(sum<x){
                cnt++;
                sum = mid;
            }else{
                sum -= x;
                i++;
            }
        }
        if(cnt<=m)
            r=mid;
        else   
            l=mid;
    }

    int cnt =0;
    int sum = 0;
    for(int i = 0; i < n;){
        int x = vec[i];

        if(sum<x){
            cnt++;
            sum=l;
        }else{
            sum -= x;
            i++;
        }
    }
    if(cnt<=m)
        result= min(result,l);
    

    cnt =0;
    sum = 0;
    for(int i = 0; i < n;){
        int x = vec[i];

        if(sum<x){
            cnt++;
            sum = r;
        }else{
            sum -= x;
            i++;
        }
    }

    if(cnt<=m)
        result= min(result,r);
    

    cout << result;

    return 0;
}