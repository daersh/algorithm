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
    int result =0;

    for(int i = 0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                int sum = arr[i]+arr[j]+arr[k];
                if(sum > arr[n-1] )
                    break;

                int l = lower_bound(arr.begin()+k+1, arr.end(),sum)-arr.begin();
                // int r = upper_bound(arr.begin()+k+1, arr.end(),sum)-arr.begin();
                
                // cout << arr[l] <<' ';
                if(sum==arr[l])
                    result = max(result,sum);
                // cout << sum << ' '<< result << '\n';
            }
        }
    }


    cout << result;

    return 0;
}

// -6 -5 -4 -4 0 1 2 2 3 7