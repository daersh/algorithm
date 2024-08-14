#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    while(1){
        cin >> a >> b >> c;
        if(a==0&& b==0 && c==0 )
            break;
        
        string result;
        int max = 0;

        if(max<a)
            max=a;
        if(max<b)
            max=b;
        if(max<c)
            max=c;

        if(a+b<=max)
            result = "Invalid";
        else if (a!=b && b!=c && a!=c)
            result = "Scalene";
        else if (a == b && b==c)
            result = "Equilateral";
        else
            result = "Isosceles";

        cout << result << endl;
    }
    return 0;

}