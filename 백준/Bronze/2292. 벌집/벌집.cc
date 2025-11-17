#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vec;
    int start=1;
    int plus=6;
    int cnt=1;
    if(n==1){
        cout << 1;
        return 0;
    }
    while(true){
        start +=plus;
        plus+=6;
        cnt++;
        if(n<=start){
            cout << cnt;
            break;
        }
    }

    return 0;
}

// 1        1 
// 2~7      6
// 8~19     12
// 20~37    18
// 38~61    24
// 62~91    30

// 1 7 19 37 61 91 