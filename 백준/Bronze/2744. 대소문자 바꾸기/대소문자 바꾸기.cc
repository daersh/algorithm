#include<iostream>
using namespace std;

int main(){
    
    string n;
    cin >> n;

    //65 97
    for(int i=0; i<n.length();i++){
        if(n[i]<97)cout << (char)(n[i]+32);
        else cout << (char)(n[i]-32);
    }
}