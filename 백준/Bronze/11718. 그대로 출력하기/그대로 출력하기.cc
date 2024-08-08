#include<iostream>

using namespace std;

int main(){
    string a;
    while(1){
        getline(cin,a);
        if(a=="")
            return 0;
        cout << a<<'\n';
    }
    
}