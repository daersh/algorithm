#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> vec;
    int maxi=1;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
        // maxi--;
        // maxi = max(maxi, temp);
    }

    sort(vec.begin(), vec.end(), greater<int>());

    for(int i=0; i<n; i++) {
        
        maxi--;
        // cout << vec[i] << ' '<< maxi <<'\n';
        maxi= max(maxi, vec[i]);
    }

    // 4 3 3 2
    //       4 5 6 7

    // 39 39 38 35 20 9
    //                6 
    // cout << maxi<< '\n';
    cout << n +maxi+1;

    return 0;
}
