#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n , c;
vector<int> vec;

int main() {
    // 집 갯수, 공유기 갯수
    
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());

    int l = 1;
    int r = vec[n-1] - vec[0]+1;
    int result = 1;
    
    while(l+1 < r){
        int cnt =1;
        int mid = (l+r) /2;
        int v = vec[0];
        for(int i = 1; i < n; i++){
            if(vec[i] - v >= mid){
                cnt++;
                v = vec[i];
            }
        }
        
        if(cnt >= c){
            if(result < mid)
                result = mid;
            l = mid;
            continue;
        }
        r = mid;
    }
    
    cout << result;
    return 0;
}