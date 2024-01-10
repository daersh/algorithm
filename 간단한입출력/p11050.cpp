#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int n1=1;
    int m1=1;
    for(int i=0; i< m;i++){
        n1*=(n-i);
    }
    for(int i=1; i<= m;i++){
        m1*=i;
    }
    cout << n1/m1;
}