#include <iostream>

using namespace std;

int main(){
    while(true){
        string s;
        int a, b;
        
        cin>> s >> a >> b;
        if(s=="#")
            return 0;
        if(a > 17 || b>=80 ){
            cout << s << ' '<< "Senior\n";
        }else{
            cout << s << ' '<< "Junior\n";
        }
    }
}