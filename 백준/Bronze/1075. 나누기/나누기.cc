#include <iostream>

using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;
    n /=100;
    n*=100;
    long long x= n/m;
 
    if(x*m==n){
        cout << "00"; 
        return 0;
    }else{
        long long a = m *(x+1) - n;

        if(a<10){
            cout << '0' << a;
        }else {
            cout << a;
        }
    }
    
}