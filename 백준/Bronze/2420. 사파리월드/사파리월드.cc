#include<iostream>
using namespace std;

int main(){
    long long n,m;
    cin >> n >> m;
    n-=m;
    if(n<0)n*=-1;
    cout<< n;
}