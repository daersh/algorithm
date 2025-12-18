#include <iostream>
using namespace std;

int main(){
     int n ;
     cin >> n ;
     int cnt=0;
     for(int i=n;i>0;i--){
        for(int j=cnt;j>0;j--)
            cout <<' ';
        for(int j=i;j>0;j--)
            cout <<'*';

        cnt++;
        cout <<'\n';
     }
}