#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>


using namespace std;
typedef pair<int,int> pii;

//10000 0000
int main(){
     ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n , k;
    cin >> n >> k;
    
    int l = 1;
    int r = k;


    while(l+1<r){
        int mid = (l + r) / 2;
        int cnt = 0;

        for(int i = 1; i <= k; i++){
            if(i>n)
                break;
            cnt += min(n, mid/i);
        }

        if(cnt < k){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << r;
}

// 1
// 1

// 1 2
// 2 4
// 1
// 2 2 4

// 1 2 3
// 2 4 6
// 3 6 9
// 1 
// 2 2 4
// 3 3 6 6 9

// 1 2 3 4
// 2 4 6 8
// 3 6 9 12
// 4 8 12 16

// 1 
// 2 2 4
// 3 3 6 6 9
// 4 4 8 8 12 12 16


// 1   2   3   4   5
// 2   4   6   8  10
// 3   6   9  12  15
// 4   8  12  16  20
// 5  10  15  20  26


// 1
// 2 2 4
// 3 3 6 6 9
// 4 4 8 8 12 12 16
// 5 5 10 10 15 15 20 20 25
