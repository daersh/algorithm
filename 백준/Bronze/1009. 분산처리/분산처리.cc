#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n ;
    cin >> n;
    for( int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        int x=0;
        int p=1;
        for(int j=0; j<b; j++){
            p*=a;
            if(p>10) p%=10;
        }
        cout << (!p? 10 : p )<< "\n";
    }
}