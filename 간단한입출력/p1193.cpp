#include <iostream>
using namespace std;

int main(){
    

    //누적합 X
    int x=0;
    int cnt=1;
    int n;
    cin >> n;

    while(x<n)
    {
        x+=cnt;
        cnt++;
    }
    
    int cmp= x-n;

    if(cnt%2==0)
        cout << cmp+1 <<'/' << cnt-cmp-1;
    else    
        cout << cnt-cmp-1 <<'/' << cmp+1 ;

}