#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

bool in(int s,int e,int x){
    // cout << s << e << x<<'\n';
    return x>=s && x<=e;
}

int main(int argc, char **argv){
    int n,m, t;
    cin >> n >>m >>t;
    int s=1;
    int e=m;
    int x,y;
    int cnt=0;
    for(int i =0 ; i<t;i++){
        cin >> x;
        if(in(s,e,x)){
            continue;
        }else{
            if(x>e)
                y= x-e;
            else if(x<s)
                y= x-s;
            cnt+=abs(y);
            s+=y;
            e+=y; 
        }
        // cout << "cnt: " << cnt <<'\n';
    }
    cout << cnt;
}

