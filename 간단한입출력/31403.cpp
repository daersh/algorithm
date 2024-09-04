#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    int a , b ,c;
    cin >> a >> b>> c;
    cout << a+b-c<<'\n';
    string str = to_string(a)+ to_string(b);
    a = stoi(str);
    cout << a-c;
    return 0;
}