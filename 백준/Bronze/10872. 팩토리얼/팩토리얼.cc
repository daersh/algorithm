#include<iostream>
using namespace std;

int main(){
    int a;
    long long n=1;
    cin >> a;
    for(int i=a;i>0;i--)n*=i;
    cout << n;
}