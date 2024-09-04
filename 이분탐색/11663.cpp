#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n ,m;
    cin >> n >> m;
    vector<int> arr;

    int x;

    for(int i=0; i<n; i++){
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    int result =0;

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        int l = lower_bound(arr.begin(), arr.end(),x)-arr.begin();
        int r = upper_bound(arr.begin(), arr.end(),y)-arr.begin();

        cout << r - l <<'\n';
    }


    // cout << result;

    return 0;
}

