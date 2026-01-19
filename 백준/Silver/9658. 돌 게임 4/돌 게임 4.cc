#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n;
    cin >> n; 
    vector<bool> v(n+1,0); 
    v[1]=1;
    v[2]=0;
    v[3]=1;
    v[4]=0;
    for(int i=5; i<=n;i++) v[i] = (v[i-1] || v[i-3] || v[i-4] )? 0 : 1;    
    cout << (v[n]?"CY":"SK");
}