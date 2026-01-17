#include <iostream>
#include <vector> 

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> vec(n+1,0);
    vec[1]=0; 
    vec[2]=1; 
    vec[3]=0; 
    vec[4]=0; 
    for(int i=5;i<=n;i++)
        vec[i]=(vec[i-1] || vec[i-3] || vec[i-4])?0:1;
    cout << (!vec[n]?"SK":"CY");
}