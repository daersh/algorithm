#include <iostream>
#include <string>
#include <cmath> 

using namespace std;

const long long MOD = 1234567891;

int main() {
    
    int n;
    cin >> n;
    string str;
    cin >> str;
    unsigned long long total = 0;
    unsigned long long next = 1; 
    
    for (int i = 0; i < n; ++i) {
        
        long long x = str[i] - 'a' + 1;
        long long v = (x * next)%MOD;
        total = (total + v) % MOD;
        next = (next * 31) % MOD;
    }
    
    cout << total << '\n';
    
    return 0;
}