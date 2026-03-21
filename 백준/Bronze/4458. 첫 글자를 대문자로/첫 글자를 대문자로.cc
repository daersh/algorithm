#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//    getline(cin,x); 문열ㅣㅂ력받기

int main(){
    int a,b,c,d ;
    string x;
   
    cin >> d;

    cin.ignore();
    
    for(int i=0; i<d; i++){
    
        getline(cin,x);
        x[0]= toupper(x[0]);
        
        cout<< x << '\n';
    }
}

 
