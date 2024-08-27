#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n ;
    cin >> n;
    vector<int> arr;

    int x;

    for(int i=0; i<n; i++){
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    long long cnt =0;
    for(int i = 0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
        
            int sum = arr[i]+arr[j];
            
            sum*=-1;
            int l = lower_bound(arr.begin()+j+1, arr.end(),sum)-arr.begin();
            int r = upper_bound(arr.begin()+j+1, arr.end(),sum)-arr.begin();
            cnt+= r-l;
        }
    }


    cout << cnt;

    return 0;
}

// -6 -5 -4 -4 0 1 2 2 3 7