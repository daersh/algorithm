#include <iostream>
using namespace std;


void pp(int cnt){
    if(cnt==2){
        return;
    }
    int x=cnt-2;
    for(int i=0; i<x;i++){
        cout << "********";
    }cout <<'\n';
    for(int i=0;i<x;i++){
        cout << "* * * *";
        if(i!=x-1){
            cout <<" ";
        }
    }cout << '\n';
    for(int i=0;i<x;i++){
        cout << "**  **";
        if(i!=x-1){
            cout <<"  ";
        }
    }cout << '\n';
    for(int i=0;i<x;i++){
        cout << "*   *";
        if(i!=x-1){
            cout <<"   ";
        }
    }cout << '\n';
    for(int i=0;i<x;i++){
        cout << "****";
        if(i!=x-1){
            cout <<"    ";
        }
    }cout << '\n';
    for(int i=0;i<x;i++){
        cout << "* *";
        if(i!=x-1){
            cout <<"     ";
        }
    }cout << '\n';
    for(int i=0;i<x;i++){
        cout << "**";
        if(i!=x-1){
            cout <<"      ";
        }
    }cout << '\n';
    for(int i=0;i<x;i++){
        cout << "*";
        if(i!=x-1){
            cout <<"       ";
        }
    }
    if(cnt!=3)cout << '\n';
    pp(cnt-1);
}

int main(){
    int n;
    cin >> n;
    if(n==0){
        cout << '*';
        return 0;
    }else if(n==1){
        cout << "**\n*";
        return 0;
    }else if(n==2){
        cout << "****\n* *\n**\n*";
        return 0;
    }
    pp(n);
}