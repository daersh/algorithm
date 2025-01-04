#include <iostream>

using namespace std;

int main(){
    string a,b;
    cin >> a;
    cin >> b;
    
    cout << ((a.length()>=b.length())? "go" : "no");
    
    return 0;
}