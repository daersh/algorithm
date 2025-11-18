#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;

int loop(int map_len, int r, int c); 

int main(){
    int n, r ,c;
    cin >> n >> r >> c;
    int map_len = 1;
    for(int i=0;i<n;i++){
        map_len*=2;
    }

    int result = loop(map_len,r,c);

    cout << result;
    return 0;
}

int loop(int map_len, int r,int c){
    // cout << "map_len: "<<map_len<<" r: "<<r <<" c: " <<c <<'\n';
    if(map_len==0||(r==0 && c==0)){
        return 0;
    }
    int half= map_len/2;
    if(r>=half && c>= half){
        // cout << "1 - ";
        int start= half*half*3;
        // cout << "start: "<<start<<'\n';
        return start+loop(half,r-half,c-half);
    }
    if(r>=half && c< half){
        // cout << "2 - ";
        int start = half*half*2;
        // cout << "start: "<<start<<'\n';
        return start+loop(half,r-half,c);
    }
    if(r<half && c>=half){
        // cout << "3 - ";
        int start = half*half*1;
        // cout << "start: "<<start<<'\n';        
        return start+loop(half,r,c-half);
    }
    if(r<half && c<half){
        // cout << "4 - ";
        int start= 0;
        // cout << "start: "<<start<<'\n';
        return start+loop(half,r,c);
    }
    return 0;
}

// 0 16 64 
// 0 44 88 

// 16 16 198

