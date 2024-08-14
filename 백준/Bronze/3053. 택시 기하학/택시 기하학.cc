#include <iostream>

using namespace std;

int main(){
    double n;
    cout<<fixed;
    cout.precision(6);
    cin >> n ;
    cout << 3.14159265359*n*n << '\n';
    cout << 2*n*n;
}