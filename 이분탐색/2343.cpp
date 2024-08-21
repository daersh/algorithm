#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n , m ;
    cin >> n >> m;
    vector<int> vec;

    int x;
    int v = 0;
    for(int i = 0; i <n;i++) {
        cin >> x;
        vec.push_back(x);
        v= max(x,v);
    }

    x = 1000000000;
    int l = v;
    int r = x;
    int mid;
    
    while(l<=r) {
        mid = (l+r)/2;

        int cnt =1;
        int s=0;
        for(int i=0; i<n;){
            s+=vec[i];
            if(s<=mid)
                i++;
            else{
                cnt++;
                s=0;
            }
        }
        
        
        if(cnt<=m){
            x=min(mid,x);
            r= mid-1;
        }
        else 
            l=mid+1;
    }
    cout << x;
    return 0;

}
