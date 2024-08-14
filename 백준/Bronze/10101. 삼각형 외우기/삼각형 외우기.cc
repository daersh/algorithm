#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    string result;
    if(a+b+c!=180)
        result = "Error";
    else if (a!=b && b!=c && a!=c)
        result = "Scalene";
    else if (a == b && b==c)
        result = "Equilateral";
    else
        result = "Isosceles";

    cout << result << endl;

    return 0;

}