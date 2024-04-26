#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct st{
    int s;
    int e;
    int cnt;
    st(int s, int e, int cnt) : s(s), e(e){

    }
};

int main(){

    int n;
    cin >> n;
    int i=9;
    int sum=9;
    int start=9;
    queue<st> q;
    q.push(st(1,9,9));

    for(int i=1; i<n;i++) {
        int z=q.size();
        for(int j=0;j<z;j++){
            st a = q.front();
            q.pop();
            if(a.cnt==0) continue;
            if(a.s==0){
                sum += a.cnt*2-1;
                q.push(st(a.s-1,a.e-1,a.cnt-1));
                q.push(st(a.s+1,a.e+1,a.cnt));
            }else if(a.e==0){
                sum += a.cnt*2-1;
                //123456789
                //0123455689
                q.push(st(a.s+1,a.e,a.cnt-1));
                q.push(st(a.s-1,a.e-1,a.cnt));
            }else{
                sum += a.cnt*2;
                q.push(st(a.s-1,a.e-1,a.cnt));
                q.push(st(a.s+1,a.e+1,a.cnt));
            }
            cout<<sum<<'\n';
        }
    }
    cout << sum;
}

/**
 * 1:                            9
 * 2:             8                        +9
 * 3:     
 * 5: 
 * 6: 
 * 
 * 1
 * 1 2 3 4 5 6 7 8 9 
 * 2
 * 2 3 4 5 6 7 8 9
    * 3 4 5 6 7 8
        * 4 5 6 7 8 9
        * 2 3 4 5 6 7
    * 1 2 3 4 5 6 7 8
        * 2 3 4 5 6 7 8 9
        * 0 1 2 3 4 5 6 7 
 * 0 1 2 3 4 5 6 7 8
    * 1 2 3 4 5 6 7 8 9
        * 2 3 4 5 6 7 8 9
        * 0 1 2 3 4 5 6 7 8
    * 0 1 2 3 4 5 6 7 
        * 1 2 3 4 5 6 7 8
        * 0 1 2 3 4 5 6 
 * 
 * */