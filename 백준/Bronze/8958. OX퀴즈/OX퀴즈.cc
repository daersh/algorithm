#include <iostream>
#include <string>
using namespace std;
//    getline(cin,x); 문열ㅣㅂ력받기

int main(){
    int a,b,c,d ;
    string x;
   
    cin >> d;
    cin.ignore();

    for(int i=0; i<d; i++){
    
        c=0;
        b=1;
        getline(cin,x);

        for(a=0;a<x.length(); a++){
            if(x[a]=='O'){
                c+=b;
                b++;
            }
            else 
                b=1;
        }

        cout << c << '\n';
        
    }
}

 
